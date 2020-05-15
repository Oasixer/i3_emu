#pragma once
#include "rapidjson/document.h"
#include <vector>
#include <string>
#include <memory>

#include "str_utils.hpp"
#include "boost_utils.hpp"

namespace i3{
class Window;
class App
{
  std::string name;
  std::string fullExePath;
  std::vector<std::shared_ptr<Window> > windows;

public:
  //App();

  App(std::string pathStr);

  App(std::shared_ptr<rapidjson::Document> d);

    // :name((*d)["name"].getString())
    // ,fullExePath((*d)["fullExePath"].getString())
  

  // create app obj from window parse vec
  App(std::string name, std::vector<std::wstring> vec);
  void addWindow(std::unique_ptr<Window> win);

    //TODO
      //: name(name) 
    //, fullExePath(wstringToString((*vec)[1]))
    //{ }

  // keybinds later
  void initWindowFromVec(std::vector<std::wstring>* vec);

  const std::string getName() { return name; }
};
}
