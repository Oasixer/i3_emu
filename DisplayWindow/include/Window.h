#pragma once
#include <memory>

#include "framework.h"
#include "pch.h"

#include "Component.h"

namespace i3{
  class Composite;
  class App;
  class Rect;
  class Window : public Component {
  private:
    HWND _handle;
    std::string _title;
    std::string _fullExePath;
    int _pid;
    std::shared_ptr<App> _app;
    std::shared_ptr<Rect> _rect;
  public:
    Window(HWND handle, std::string title, int pid, std::string fullExePath);
    
    void setApp(std::shared_ptr<App> app);

    const HWND getHandle() const { return _handle; };

    std::string getFullExePath() const { return _fullExePath; };

    void WinMove(int deltaTop, int deltaRight, int deltaBottom, int deltaLeft);
  };
}
