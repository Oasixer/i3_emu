#include <boost/filesystem.hpp>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include <string>

#include "str_utils.h"
#include "boost_utils.h"

#include "Window.h"
#include "App.h"

namespace bfs = boost::filesystem;
namespace i3{
  App::App(std::string pathStr){
    auto jsonStr = utils::readFile(pathStr);
    const char* jsonCStr = jsonStr.c_str();
    if (jsonStr == "null" || jsonStr == ""){
      fprintf(stderr, "JSON parse error on file: %s, file contents are: %s", pathStr.c_str(), jsonCStr);
      exit(EXIT_FAILURE);
    }
    rapidjson::Document d;
    rapidjson::ParseResult ok = d.Parse(jsonCStr); // This line crashes if the json string is invalid
    _name = d["name"].GetString();
    _fullExePath = d["fullExePath"].GetString();
  }

  App::App(std::string name, std::string fullExePath){
    _name = name;
    _fullExePath = fullExePath;
  }

  // void App::addWindow(Window& window){
    // _windows.push_back(window);
  // }

  const std::string App::toJsonString() {
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("name");
    writer.String(_name.c_str());
    writer.Key("fullExePath");
    writer.String(_fullExePath.c_str());
    writer.Key("wsPref");
    writer.Int(_wsPref);
    writer.Key("keybinds"); //TODO keybinds
    writer.StartArray();
    for (unsigned i = 0; i < 4; i++)
      writer.Uint(i);
    writer.EndArray();
    writer.EndObject();
    std::string str{ s.GetString() }; 
    return str;
  }

  // rapidjson::StringBuffer App::toJsonStringBuffer() {
    // rapidjson::StringBuffer s;
    // rapidjson::Writer<rapidjson::StringBuffer> writer(s);
    // writer.StartObject();
    // writer.Key("name");
    // writer.String(name.c_str());
    // writer.Key("fullExePath");
    // writer.String(fullExePath.c_str());
    // writer.Key("wsPref");
    // writer.Int(wsPref);
    // writer.Key("keybinds"); //TODO keybinds
    // writer.StartArray();
    // writer.EndArray();
    // writer.EndObject();
    // return s;
  // }

  // std::vector<Window>& App::getWindows(){
    // return _windows;
  // }


  // bool App::isOpen() const {
    // return !_windows.empty();
  // }
  
  // Window* App::findWindowByHandle(HWND handle){
    // for (auto& window : _windows){
      // if (window.getHandle() == handle){
        // return &window;
      // }
    // }
    // return nullptr;
  // }

  std::ostream& operator<<(std::ostream& os, const App& app)
  {
    os << app._name << std::endl << app._fullExePath << std::endl;
    return os;
  }

}
