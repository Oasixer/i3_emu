#include <iostream>
#include <array>

#include "win32_utils.h"
#include "win32debug_utils.h"
#include "App.h"
#include "Rect.h"
#include "Window.h"

namespace i3{
  Window::Window(HWND handle, std::string title, int pid, std::string fullExePath){
    _handle = handle;
    _title = title;
    _pid = pid;
    _fullExePath = fullExePath;
    _rect = Rect(handle);
  }

  void Window::setApp(App &app){
    _app = &app;
  }
  
  void Window::winMove(int deltaTop, int deltaRight, int deltaBottom, int deltaLeft){
    // So that compatibility is retained, don't set ErrorLevel for commands that are native to AutoIt2
    // but that AutoIt2 doesn't use ErrorLevel with (such as this one).
    HWND target_window = _handle;
    Rect rect = _rect; // TODO remove this pointless alias
    rect.mvTop(deltaTop);
    rect.mvRight(deltaRight);
    rect.mvBottom(deltaBottom);
    rect.mvLeft(deltaLeft);
    // if (!GetWindowRect(target_window, &rect))
      // return OK;  // Can't set errorlevel, see above.

    MoveWindow(target_window
      , rect.getLeft()  // X-position
      , rect.getTop()   // Y-position
      , rect.getRight() - rect.getLeft() // width
      , rect.getBottom() - rect.getTop() // height
      , TRUE);  // Do repaint.
    // DoWinDelay;
    std::cout << "did the thing" << std::endl;
    // return OK;
  }
}
