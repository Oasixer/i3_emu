#pragma once
#include <vector>
#include <string>
#include <memory>

#include "pch.h"
#include "framework.h"

namespace i3{
  class App;
  class Window;
  class WindowData
  {
    private:
      int wsNum;
      std::shared_ptr<App> appPtr;
      std::string title;
      int pid;
      std::shared_ptr<Window> _window;
      HWND hwnd;
    public:
      WindowData(HWND &hwnd, int ws, std::string title, int pid);

      void setAppPtr(std::shared_ptr<App> appPtr);
      void setWindow(std::shared_ptr<Window> window);
      std::shared_ptr<Window> getWindow() const { return _window; };
  };
}
