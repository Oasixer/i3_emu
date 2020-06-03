#pragma once
#include "rapidjson/document.h"

#include <vector>
#include <string>
#include <iostream>
#include <memory>

#include "framework.h"
#include "pch.h"

namespace i3{
  // class Window;
  class App// : public std::enable_shared_from_this<App>
  {
    private:
      std::string _name;
      std::string _fullExePath;
      // std::vector<Window> _windows;
      int _wsPref; // preferred workspace for this app to open into

    public:
      App(std::string pathStr);
      App(std::string name, std::string fullExePath);
        // :_name{name}
        // ,_fullExePath{fullExePath}
      // { };

      //const std::shared_ptr<App> getptr() { return shared_from_this(); }

      // void addWindow(Window& window);

      // std::vector<Window>& getWindows();

      bool isOpen() const;

      const std::string toJsonString();

      // keybinds later
      // void initWindowDataFromVec(std::vector<std::wstring> vec);

      auto getName() const { return _name; }

      // Window* findWindowByHandle(HWND handle);

      friend std::ostream& operator<<(std::ostream& os, const App& app);
  };
}
