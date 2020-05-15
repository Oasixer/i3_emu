#include <memory>

#include "App.h"
#include "Window.h"

namespace i3{
  Window::Window(int ws, std::string title, int pid){// std::shared_ptr<App> appPtr){
    ws=ws;
    title=title;
    pid=pid;
    // appPtr = std::move(appPtr);
    // std::unique_ptr<Window> backref;
    // backref.reset(this);
    // appPtr -> addWindow(std::move(backref));
  }

  void Window::setAppPtr(std::shared_ptr<App> appPtr){
    appPtr = appPtr;
  }
}
