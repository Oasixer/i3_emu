#include <boost/filesystem.hpp>
#include <string>

#include "str_utils.hpp"
#include "boost_utils.hpp"

#include "Window.h"
#include "App.h"

namespace bfs = boost::filesystem;
namespace i3{
  App::App(std::string pathStr){
    auto jsonStr = readFile(pathStr);
    const char* jsonCStr = jsonStr.c_str();
    //const char* jsonCStr = "{\"project\":\"rapidjson\",\"stars\":10}";
    rapidjson::Document d2;
    d2.Parse(jsonCStr);
    
    name = d2["name"].GetString();
    fullExePath = d2["fullExePath"].GetString();
  }

  App::App(rapidjson::Document* d){
    name = (*d)["name"].GetString();
    fullExePath = (*d)["fullExePath"].GetString();
  }

  void App::initWindowFromVec(std::vector<std::wstring>* vec){
    
  }

  App::App(std::string name, std::vector<std::wstring>* vec){
    name=name;
    fullExePath = wstringToString((*vec)[1]);
  }

  void App::addWindow(Window* win){
    windows.push_back(win);
    win -> setAppPtr(this);
  }

}
