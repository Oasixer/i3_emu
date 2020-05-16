#include <boost/filesystem.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "boost_utils.h"
#include "str_utils.h"

#include "GlobalConfig.h"
#include "App.h"
#include "Window.h"

#include "DataContainer.h"

namespace bfs = boost::filesystem;

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
          apps.push_back(std::make_shared<App>(itr->path().string()));
        }
      }
    }
  }

  void DataContainer::writeAppsToJson(){
    for (const auto& app : apps){
      // make an empty document, and start writing to all of its fields.
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
      matchingAppPtr -> addWindow(std::make_unique<Window>(hwnd, workspaceNum, title, pidInt));
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
