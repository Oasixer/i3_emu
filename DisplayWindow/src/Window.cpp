#include "App.h"
#include "Window.h"

namespace i3{
  void Window::setApp(std::shared_ptr<App> app){
    _app = app;
  }
  
}
