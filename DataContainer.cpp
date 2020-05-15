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

  void DataContainer::parseOpenWindowsFromVec(std::unique_ptr<std::vector<std::vector<std::wstring> > > vecs){
    for (const auto& vec : (*vecs)){
      auto name = utils::parseNameFromFullExePath(vec[1]);
      auto matchingAppPtr = findAppByNameOrCreateNewIfNeeded(name, vec);
      //std::cout << "made new app, name: " << matchingAppPtr->getName();
      // std::wcout << L"Title: " << vec[0] << std::endl;
      int workspaceNum = 0; // temp, should get this from config potentially future TODO
      auto title = utils::wstringToString(vec[0]);
      auto pidStr = utils::wstringToString(vec[2]);
      int pidInt = std::stoi(pidStr);
      matchingAppPtr -> addWindow(std::make_unique<Window>(workspaceNum, title, pidInt));
    }
  }
}
