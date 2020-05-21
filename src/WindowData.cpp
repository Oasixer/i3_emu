#include <memory>

#include "App.h"
#include "WindowData.h"

namespace i3{
  WindowData::WindowData(HWND &hwnd, int ws, std::string title, int pid){// std::shared_ptr<App> appPtr){
    hwnd=hwnd;
    wsNum=ws;
    title=title;
    pid=pid;
  }

  void WindowData::setAppPtr(std::shared_ptr<App> appPtr){
    appPtr = appPtr;
  }
}