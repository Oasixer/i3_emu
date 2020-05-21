#pragma once
#include <memory>

#include "framework.h"
#include "pch.h"

#include "Component.h"
namespace i3{
  class Composite;
  class App;
  class Window : public Component {
  private:
    HWND _handle;
    std::string _title;
    std::string _fullExePath;
    int _pid;
    std::shared_ptr<App> _app;
  public:
    Window(HWND handle, std::string title, int pid, std::string fullExePath)
      :_handle{handle}
    ,_title{title}
    ,_pid{pid}
    ,_fullExePath{fullExePath}
    { };
    
    void setApp(std::shared_ptr<App> app);

    const HWND getHandle() const { return _handle; };

    std::string getFullExePath() const { return _fullExePath; };
  };
}
