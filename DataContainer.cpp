#include <boost/filesystem.hpp>
#include <rapidjson/document.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "boost_utils.hpp"
#include "str_utils.hpp"

// #include "GlobalConfig.h"
#include "App.h"
#include "Window.h"

#include "DataContainer.h"

namespace bfs = boost::filesystem;

namespace i3{
DataContainer::DataContainer(std::string pathToSaveDir){
  apps = {};
  //globalConfig = nullptr;

  bfs::path p (pathToSaveDir);
  bfs::directory_iterator end_itr;

  // cycle through the directory
  for (bfs::directory_iterator itr(p); itr != end_itr; ++itr)
  {
    // If it's not a directory, continue
    if (is_regular_file(itr->path())) {
      auto d = pathStrToDoc(itr->path().string());
      // auto d_alloc = d_old->GetAllocator();
      // rapidjson
      if (itr->path().string().find("global.json") != std::string::npos){
        // Parse global config
        // GlobalConfig globalConfig(d);
      }
      else{
        // Otherwise, parse app
        apps.push_back(std::make_shared<App>(d));
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

std::shared_ptr<App> DataContainer::findAppByNameOrCreateNewIfNeeded(std::string name, std::vector<std::wstring> vec){
  for (const auto appPtr : apps){
    if (appPtr->getName() == name){
      return appPtr;
    }
  }

  return std::make_shared<App>(name, vec);
}

void DataContainer::parseOpenWindowsFromVec(std::unique_ptr<std::vector<std::vector<std::wstring> > > vecs){
  for (const auto& vec : (*vecs)){
    auto name = parseNameFromFullExePath(vec[1]);
    auto matchingAppPtr = findAppByNameOrCreateNewIfNeeded(name, vec);
    // std::wcout << L"Title: " << vec[0] << std::endl;
    int workspaceNum = 0; // temp, should get this from config potentially future TODO
    auto title = wstringToString(vec[0]);
    auto pidStr = wstringToString(vec[2]);
    int pidInt = std::stoi(pidStr);
    auto newWindow = std::make_unique<Window>(workspaceNum, title, pidInt, matchingAppPtr);
    matchingAppPtr -> addWindow(std::move(newWindow));
    // ^ inside this function, newWindow should be MODIFIED by adding a ptr to the app!
  }
}
}
