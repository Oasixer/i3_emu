#include <memory>

#include "framework.h"
#include "pch.h"

#include "Component.h"

namespace i3{
  class WindowData;
  class Window : public Component {
  private:
    std::shared_ptr<WindowData> _windowData;
  public:
    Window(std::shared_ptr<WindowData> windowData);
  };
}
