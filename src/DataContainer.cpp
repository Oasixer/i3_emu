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
#include <array>

#include "boost_utils.h"
#include "str_utils.h"
#include "win32_utils.h"

#include "GlobalConfig.h"
#include "App.h"
#include "Workspace.h"
#include "Tabbed.h"
#include "Window.h"
#include "Monitor.h"

#include "DataContainer.h"

namespace bfs = boost::filesystem;
namespace rj = rapidjson;

namespace i3{
  DataContainer::DataContainer(){
    //_globalConfig = GlobalConfig();
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

          //_globalConfig = GlobalConfig(itr->path().string());
        }
        else{
          // Otherwise, parse app
          // _apps.push_back(std::make_shared<App>(itr->path().string()));
        }
      }
    }
  }

  // void DataContainer::writeAppsToJson(){
    // for (auto& app : _apps){
      // // make an empty document, and start writing to all of its fields.
      // rj::Document d;
      // auto jsonStr{ app.toJsonString() };
      // std::cout << jsonStr << std::endl;
      // auto jsonCStr = jsonStr.c_str();
      // d.Parse(jsonCStr);

      // std::string savePath { "save\\" };
      // std::string jsonFt { ".json" };
      // std::string filename { savePath + app.getName() + jsonFt };
      // std::ofstream ofs { filename, std::ofstream::out };
      
       // if ( !ofs.is_open() )
       // {
        // std::cerr << "Could not open file for writing!\n";
        // return; //EXIT_FAILURE;
       // }

       // rj::OStreamWrapper osw { ofs };
       // rj::Writer<rj::OStreamWrapper> writer2 { osw };
       // d.Accept( writer2 );
      // --------

      // rj::StringBuffer buffer;
      // rj::Writer<rj::StringBuffer> writer(buffer);
      // d.Accept(writer);

      // ofs << buffer.GetString();

      // std::cout << buffer.GetString();

      //}
  //}

  void DataContainer::createDefaultWorkspaceLayout(){
    auto& windows = utils::getOpenWindows();
    auto primaryMonitor = findMonitorByHandle(utils::GetPrimaryMonitorHandle());
    assert(primaryMonitor != nullptr);
    auto& newWorkspace = primaryMonitor->add(std::make_unique<Workspace>(0));
    // auto& tabbed = newWorkspace.add(std::make_unique<Tabbed>());

    for (auto& window : windows){
      //tabbed.add(std::move(window));
    }
  }

  void DataContainer::applyDefaultWorkspaceLayout(){
    // const auto focusedHandle = GetForegroundWindow();
    //auto focusedWindow = findWindowByHandle(focusedHandle);
    //assert(focusedWindow != nullptr);

    //TODO: Move every open window to monitor 0 / workspace 0, maximize every window, eventually display the tabs
  }

  // Window* DataContainer::findWindowByHandle(std::vector<unique_ptr<Window>>& windows, HWND handle){
    // for (auto& window : windows){
      // if (window->getHandle() == handle){
        // return *window;
      // }
    // }
    // return nullptr;
  // }
  
  Monitor* DataContainer::findMonitorByHandle(HMONITOR handle){
    for (auto& monitor : _monitors){
      if (monitor->getHandle() == handle){
        return &(*monitor);
      }
    }
    return nullptr;
  }

  App& DataContainer::findAppByNameOrCreateNewIfNeeded(std::string name, std::string fullExePath){
    for (auto& app : _apps){
      if (app->getName() == name){
        return *app;
      }
    }

    _apps.push_back(std::make_unique<App>(name, fullExePath));
    return *(_apps.back());
  }
  
  //std::vector<std::unique_ptr<App>>& DataContainer::getApps(){
  //  return _apps;
  //}

  //std::vector<std::unique_ptr<Window>>& DataContainer::getWindows(){
  //  return _windows;
  //}
  
  // void DataContainer::setWindows(std::vector<std::unique_ptr<Window>>& windows){
    // _windows = windows;
  // }

  //TEMP TODO
  // void DataContainer::setMonitors(std::vector<std::unique_ptr<Monitor>>& monitors){
  void DataContainer::setMonitors(std::vector<std::shared_ptr<Monitor>>& monitors){
    _monitors = monitors;
  }

  // void DataContainer::attachApps(){
    // for (auto& window : _windows){
      // auto name = utils::parseNameFromFullExePath(window->getFullExePath());
      // auto& app = findAppByNameOrCreateNewIfNeeded(name, window->getFullExePath());
      // app.addWindow(*window);
      // window->setApp(app);
    // }
  // }
  
  // void DataContainer::attachWindowCallbacks(){
    // for (auto& window : _windows){
      // //window->regCallbackTest();
    // }


    // // Sleep(5000);
    // std::array<TCHAR, 256> className; //256 is max classname length
    // GetClassName(_windows[0]->getHandle(), className.data(), className.size());

    // WNDCLASSEX wce;
    // GetClassInfoEx(GetModuleHandle(nullptr), className.data(), &wce);

    // std::cout << "hi_" << std::endl;
  // }

  // void DataContainer::parseOpenWindowsFromVec(std::unique_ptr<std::vector<std::pair<HWND, std::vector<std::wstring> > > > pairs){
    // for (const auto& pair_ : (*pairs)){
      // auto hwnd = pair_.first;
      // auto vec = pair_.second;
      // auto name = utils::parseNameFromFullExePath(vec[1]);
      // auto matchingAppPtr = findAppByNameOrCreateNewIfNeeded(name, vec);
      // int workspaceNum = 0; // temp, should get this from config potentially future TODO
      // auto title = utils::wstringToString(vec[0]);
      // auto pidStr = utils::wstringToString(vec[2]);
      // int pidInt = std::stoi(pidStr);
      // matchingAppPtr->addWindowData(std::make_unique<WindowData>(hwnd, workspaceNum, title, pidInt));
    // }
  // }

  // void DataContainer::parseMonitorFromVec(std::unique_ptr<std::vector<std::pair<HMONITOR, LPRECT>>> vec){
    // for (const auto& dataPair : *vec){
      // monitors.push_back(std::make_shared<Monitor>(dataPair.first, dataPair.second));
    // }
  // }
  
  std::ostream& operator<<(std::ostream& os, const DataContainer& dc)
  {
    os << "DC:" << std::endl;
    for (const auto &app : dc._apps){
      os << app;
    }
    return os;
  }
}
