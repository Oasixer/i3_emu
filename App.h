#pragma once
#include "rapidjson/document.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>

namespace i3{
  class Window;
  class App : public std::enable_shared_from_this<App>
  {
    private:
      std::string name;
      std::string fullExePath;
      std::vector<std::shared_ptr<Window> > windows;
      int wsPref; // preferred workspace for this app to open into

    public:
      App(std::string pathStr);

      // App(std::shared_ptr<rapidjson::Document> d);

      // create app obj from window parse vec
      App(std::string name, std::vector<std::wstring> vec);
      
      const std::shared_ptr<App> getptr() { return shared_from_this(); }

      void addWindow(std::unique_ptr<Window> win);

      const std::string toJsonString();

      // keybinds later
      // void initWindowFromVec(std::vector<std::wstring> vec);

      const std::string getName() { return name; }

      friend std::ostream& operator<<(std::ostream& os, const App& app);
  };
}
