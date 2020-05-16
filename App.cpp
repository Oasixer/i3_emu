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
    name = d["name"].GetString();
    fullExePath = d["fullExePath"].GetString();
  }

  App::App(std::string name_, std::vector<std::wstring> vec){
    name=name_;
    fullExePath = utils::wstringToString((vec)[1]);
    wsPref=0;
  }

  void App::addWindow(std::unique_ptr<Window> win){
    std::shared_ptr<Window> winSharedPtr = std::move(win);
    windows.push_back(winSharedPtr);
    winSharedPtr -> setAppPtr(getptr());
  }

  const std::string App::toJsonString() {
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("name");
    writer.String(name.c_str());
    writer.Key("fullExePath");
    writer.String(fullExePath.c_str());
    writer.Key("wsPref");
    writer.Int(wsPref);
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

  std::ostream& operator<<(std::ostream& os, const App& app)
  {
    os << app.name << std::endl << app.fullExePath << std::endl;
    return os;
  }

}
