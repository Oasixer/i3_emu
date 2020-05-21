#include "WindowData.h"
#include "Window.h"

namespace i3{
  Window::Window(std::shared_ptr<WindowData> windowData){
    _windowData = windowData;
  }
}
