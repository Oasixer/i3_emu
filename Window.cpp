#include <memory>

#include "App.h"
#include "Window.h"

namespace i3{
  Window::Window(HWND hwnd, int ws, std::string title, int pid){// std::shared_ptr<App> appPtr){
    hwnd=hwnd;
    wsNum=ws;
    title=title;
    pid=pid;
  }

  void Window::setAppPtr(std::shared_ptr<App> appPtr){
    appPtr = appPtr;
  }
}
