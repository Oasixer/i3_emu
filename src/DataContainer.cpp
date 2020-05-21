#include <boost/filesystem.hpp>
#include "rapidjson/stringbuffer.h"
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/writer.h>
//#include "rapidjson/prettywriter.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "boost_utils.h"
#include "str_utils.h"

#include "GlobalConfig.h"
#include "App.h"
#include "WindowData.h"
#include "Workspace.h"
#include "Tabbed.h"
#include "Window.h"
#include "MonitorData.h"

#include "DataContainer.h"

namespace bfs = boost::filesystem;
namespace rj = rapidjson;

namespace i3{
  DataContainer::DataContainer(){
  }

  DataContainer::DataContainer(std::string pathToSaveDir){
    bfs::path p (pathToSaveDir);
    bfs::directory_iterator end_itr;

    // cycle through the directory
    for (bfs::directory_iterator itr(p); itr != end_itr; ++itr)
    {
      // If it's not a directory, continue
      if (is_regular_file(itr->path())) {
        if (itr->path().string().find("global.json") != std::string::npos){
          // Parse global config
          //auto d = utils::pathStrToDoc(itr->path().string());
          globalConfig = std::make_shared<GlobalConfig>(itr->path().string());
        }
        else{
          // Otherwise, parse app
          // apps.push_back(std::make_shared<App>(itr->path().string()));
        }
      }
    }
  }

  void DataContainer::writeAppsToJson(){
    for (const auto& app : apps){
      // make an empty document, and start writing to all of its fields.
      rj::Document d;
      auto jsonStr{ app->toJsonString() };
      std::cout << jsonStr << std::endl;
      auto jsonCStr = jsonStr.c_str();
      d.Parse(jsonCStr);

      std::string savePath { "save\\" };
      std::string jsonFt { ".json" };
      std::string filename { savePath + app->getName() + jsonFt };
      std::ofstream ofs { filename, std::ofstream::out };
      
       if ( !ofs.is_open() )
       {
        std::cerr << "Could not open file for writing!\n";
        return; //EXIT_FAILURE;
       }

       rj::OStreamWrapper osw { ofs };
       rj::Writer<rj::OStreamWrapper> writer2 { osw };
       d.Accept( writer2 );
      // --------

      // rj::StringBuffer buffer;
      // rj::Writer<rj::StringBuffer> writer(buffer);
      // d.Accept(writer);

      // ofs << buffer.GetString();

      // std::cout << buffer.GetString();

      }
  }

  void DataContainer::CreateWorkspaceLayout(){
    auto newWorkspace = std::make_shared<Workspace>(0, getptr());
    workspaces.push_back(newWorkspace);
    
    // The following line is the source of the error.
    // The Tabbed constructor takes a pointer to any object that inherits from Component.
    // In this case, I pass it a pointer to a Workspace, which extends Composite, which extends Component.
    auto tabbed = std::make_shared<Tabbed>(newWorkspace);

    newWorkspace->add(tabbed); // add tabbed layout to workspace
    
    for (const auto& app : apps){
      if (app->isOpen()) {
        // Some kind of code for specific applications to go into specific layouts could go here.
        // For now, instead, we just default to loading all the windows into workspace 0 in a tabbed layout.
        for (const auto& windowData : app->getWindowDataVec()){
          auto newWindow = std::make_shared<Window>(windowData);
          tabbed -> add(newWindow);
        }
      }
    }
  }

  std::shared_ptr<App> DataContainer::findAppByNameOrCreateNewIfNeeded(std::string name, std::vector<std::wstring> vec){
    for (const auto appPtr : apps){
      if (appPtr->getName() == name){
        return appPtr;
      }
    }

    auto newApp = std::make_shared<App>(name, vec);
    apps.push_back(newApp);
    return newApp;
  }

  void DataContainer::parseOpenWindowsFromVec(std::unique_ptr<std::vector<std::pair<HWND, std::vector<std::wstring> > > > pairs){
    for (const auto& pair_ : (*pairs)){
      auto hwnd = pair_.first;
      auto vec = pair_.second;
      auto name = utils::parseNameFromFullExePath(vec[1]);
      auto matchingAppPtr = findAppByNameOrCreateNewIfNeeded(name, vec);
      int workspaceNum = 0; // temp, should get this from config potentially future TODO
      auto title = utils::wstringToString(vec[0]);
      auto pidStr = utils::wstringToString(vec[2]);
      int pidInt = std::stoi(pidStr);
      matchingAppPtr->addWindowData(std::make_unique<WindowData>(hwnd, workspaceNum, title, pidInt));
    }
  }

  void DataContainer::parseMonitorDataFromVec(std::unique_ptr<std::vector<std::pair<HMONITOR, LPRECT>>> vec){
    for (const auto& dataPair : *vec){
      monitors.push_back(std::make_shared<MonitorData>(dataPair.first, dataPair.second));
    }
  }
  
  std::ostream& operator<<(std::ostream& os, const DataContainer& dc)
  {
    os << "DC:" << std::endl;
    for (const auto &app : dc.apps){
      os << (*app);
    }
    return os;
  }
}
