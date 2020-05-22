#include <iostream>
#include <array>

#include "win32_utils.h"
#include "win32debug_utils.h"
#include "App.h"
#include "Rect.h"
#include "Window.h"


  LRESULT CALLBACK winSubClassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
  {
      //msg_dev(toString(uMsg));
      
      std::cout << "hi" << std::endl;
      std::cout << uMsg << std::endl;

      switch(uMsg)
      {
          case WM_MOUSEMOVE:
              SetCursor(LoadCursor(NULL, IDC_HAND));
              break;

          case WM_LBUTTONDOWN:
              //msg_dev("Button down!");
            std::cout << "button" << std::endl;
              break;

          case WM_NCDESTROY:
              RemoveWindowSubclass(hwnd, &winSubClassProc, 1);
              break;

          case WM_SIZE:
              {
                std::cout << "resize!!!!" << std::endl;
                  int width = LOWORD(lParam);  // Macro to get the low-order word.
                  int height = HIWORD(lParam); // Macro to get the high-order word.

                  // Respond to the message:
                  //OnSize(hwnd, (UINT)wParam, width, height);
              }
      }

      return DefSubclassProc(hwnd, uMsg, wParam, lParam);
  }

  WNDPROC prevWndProc;

LRESULT CALLBACK myNewWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  std::cout << "HIADHIAHDIASHD" << std::endl;

    switch(uMsg)
    {
        case WM_MOUSEMOVE:
            SetCursor(LoadCursor(NULL, IDC_HAND));
            break;

        case WM_LBUTTONDOWN:
            //msg_dev("Button down!");
            break;
    }

    return CallWindowProc(prevWndProc, hwnd, uMsg, wParam, lParam);
}


namespace i3{
  Window::Window(HWND handle, std::string title, int pid, std::string fullExePath){
    _handle = handle;
    _title = title;
    _pid = pid;
    _fullExePath = fullExePath;
    _rect = std::make_shared<Rect>(handle);
  }

  void Window::setApp(std::shared_ptr<App> app){
    _app = app;
  }
  
  void Window::regCallbackTest(){

    // std::array<TCHAR, 256> className; //256 is max classname length
    // GetClassName(_handle, className.data(), className.size());

    // WNDCLASSEX wce;
    // GetClassInfoEx(GetModuleHandle(nullptr), className.data(), &wce);
    //SetClassLongPtr(_handle, GCLP_WNDPROC, reinterpret_cast<LONG_PTR>(utils::WindowProc));
    // prevWndProc = (WNDPROC) SetWindowLongPtr(_handle, GWL_WNDPROC, (LONG_PTR)&myNewWndProc);
    // bool test = SetWindowSubclass(_handle, &winSubClassProc, 1, 0);
    // auto err = utils::getLastErrorStr();
    // std::cout << err << std::endl;
    // std::array<TCHAR, 256> className2; //256 is max classname length
    // GetClassName(_handle, className2.data(), className2.size());

    // WNDCLASSEX wce2;
    // GetClassInfoEx(GetModuleHandle(nullptr), className2.data(), &wce2);
    WinMove(65, 0, 12, 315);
    auto err0 = utils::getLastErrorStr();
    std::cout <<"err0 "<< err0 << std::endl;
  }


  void Window::WinMove(int deltaTop, int deltaRight, int deltaBottom, int deltaLeft){
    // So that compatibility is retained, don't set ErrorLevel for commands that are native to AutoIt2
    // but that AutoIt2 doesn't use ErrorLevel with (such as this one).
    HWND target_window = _handle;
    Rect rect = *_rect;
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
