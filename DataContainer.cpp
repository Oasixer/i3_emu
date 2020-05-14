#include <boost/filesystem.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "boost_utils.hpp"
#include "str_utils.hpp"

#include "GlobalConfig.h"
#include "App.h"
#include "Window.h"

#include "DataContainer.h"

namespace bfs = boost::filesystem;

namespace i3{
DataContainer::DataContainer(std::string pathToSaveDir){
  std::vector<App*> apps;
  globalConfig = nullptr;

  bfs::path p (pathToSaveDir);
  bfs::directory_iterator end_itr;

  // cycle through the directory
  for (bfs::directory_iterator itr(p); itr != end_itr; ++itr)
  {
    // If it's not a directory, continue
    if (is_regular_file(itr->path())) {
      auto dPtr = pathStrToDoc(itr->path().string());
      if (itr->path().string().find("global.json") != std::string::npos){
        // Parse global config
        GlobalConfig globalConfig(dPtr);
      }
      else{
        // Otherwise, parse app
        App newApp(dPtr);
        apps.push_back(&newApp);
      }
    }
  }
}

std::string parseNameFromFullExePath(std::wstring fullExePath){
  std::string s = wstringToString(fullExePath);
  std::string delimiter = "\\"; // TODO: Make sure this actually works
  std::string token = s.substr(s.find_last_of(delimiter));
  return token;
}

App* DataContainer::findAppByNameOrCreateNewIfNeeded(std::string name, std::vector<std::wstring> vec){
  for (const auto appPtr : apps){
    if (appPtr->getName() == name){
      return appPtr;
    }
  }
  
  App newApp(name, &vec);
  
  return &newApp;
}

void DataContainer::parseOpenWindowsFromVec(std::vector<std::vector<std::wstring> >* vecs){
  for (const auto& vec : (*vecs)){
    auto name = parseNameFromFullExePath(vec[1]);
    auto matchingAppPtr = findAppByNameOrCreateNewIfNeeded(name, vec);
    // std::wcout << L"Title: " << vec[0] << std::endl;
    int workspaceNum = 0; // temp, should get this from config potentially future TODO
    auto title = wstringToString(vec[0]);
    auto pidStr = wstringToString(vec[2]);
    int pidInt = std::stoi(pidStr);
    Window newWindow(workspaceNum, title, pidInt, matchingAppPtr);
    matchingAppPtr -> addWindow(&newWindow);
    // ^ inside this function, newWindow should be MODIFIED by adding a ptr to the app!
  }
}
}
