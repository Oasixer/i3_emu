#pragma once
#include <string>
#include <utility>

#include "str_utils.h"
#include "framework.h"
#include "pch.h"

namespace utils{
  inline std::string getLastErrorStr(){
    // LPTSTR errorText = NULL;
    const DWORD ERROR_TEXT_SIZE = 1024;
    WCHAR errorText[1024];
    auto lastErr = GetLastError();

    FormatMessage(
      // use system message tables to retrieve error text
      FORMAT_MESSAGE_FROM_SYSTEM
      // allocate buffer on local heap for error text
      // |FORMAT_MESSAGE_ALLOCATE_BUFFER
      // Important! will fail otherwise, since we're not 
      // (and CANNOT) pass insertion parameters
      |FORMAT_MESSAGE_IGNORE_INSERTS,  
      NULL,    // unused with FORMAT_MESSAGE_FROM_SYSTEM
      lastErr,
      MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
      errorText,  // output 
      ERROR_TEXT_SIZE, // minimum size for output buffer
      NULL
    );   // arguments - see note 
    std::string errorStr;

    if ( NULL != errorText )
    {
      std::wstring errorWStr(errorText);
      errorStr = wstringToString(errorWStr);
      // release memory allocated by FormatMessage()
      //LocalFree(errorText);
      //errorText = NULL;
    }
    return errorStr;
  }
    
// TEMP TEST CODE FOR REGISTERING HANDLER FUNCTIONS
// - turns out to not work on other threads

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

  // LRESULT CALLBACK winSubClassProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
  // {
      // //msg_dev(toString(uMsg));
      
      // std::cout << "hi" << std::endl;
      // std::cout << uMsg << std::endl;

      // switch(uMsg)
      // {
          // case WM_MOUSEMOVE:
              // SetCursor(LoadCursor(NULL, IDC_HAND));
              // break;

          // case WM_LBUTTONDOWN:
              // //msg_dev("Button down!");
            // std::cout << "button" << std::endl;
              // break;

          // case WM_NCDESTROY:
              // RemoveWindowSubclass(hwnd, &winSubClassProc, 1);
              // break;

          // case WM_SIZE:
              // {
                // std::cout << "resize!!!!" << std::endl;
                  // int width = LOWORD(lParam);  // Macro to get the low-order word.
                  // int height = HIWORD(lParam); // Macro to get the high-order word.

                  // // Respond to the message:
                  // //OnSize(hwnd, (UINT)wParam, width, height);
              // }
      // }

      // return DefSubclassProc(hwnd, uMsg, wParam, lParam);
  // }

  // WNDPROC prevWndProc;

// LRESULT CALLBACK myNewWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
// {
  // std::cout << "HIADHIAHDIASHD" << std::endl;

    // switch(uMsg)
    // {
        // case WM_MOUSEMOVE:
            // SetCursor(LoadCursor(NULL, IDC_HAND));
            // break;

        // case WM_LBUTTONDOWN:
            // //msg_dev("Button down!");
            // break;
    // }

    // return CallWindowProc(prevWndProc, hwnd, uMsg, wParam, lParam);
}




}
