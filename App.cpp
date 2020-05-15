#include <boost/filesystem.hpp>
#include <string>

#include "str_utils.h"
// #include "boost_utils.hpp"

#include "Window.h"
#include "App.h"

namespace bfs = boost::filesystem;
namespace i3{
  App::App(std::string pathStr){
    // auto jsonStr = utils::readFile(pathStr);
    // const char* jsonCStr = jsonStr.c_str();
    // rapidjson::Document d;
    // d.Parse(jsonCStr);
    
    // name = d["name"].GetString();
    // fullExePath = d["fullExePath"].GetString();
    name = "a";
    fullExePath = "a";
  }

  // App::App(std::shared_ptr<rapidjson::Document> d){
    // name = (*d)["name"].GetString();
    // fullExePath = (*d)["fullExePath"].GetString();
  // }



  App::App(std::string name_, std::vector<std::wstring> vec){
    name=name_;
    fullExePath = "temp";//utils::wstringToString((vec)[1]);
  }

  void App::initWindowFromVec(std::vector<std::wstring> vec) {

  }

  void App::addWindow(std::unique_ptr<Window> win){
    std::shared_ptr<Window> winSharedPtr = std::move(win);
    windows.push_back(winSharedPtr);
    winSharedPtr -> setAppPtr(getptr());
  }

}
