#pragma once
#include <memory>
#include <vector>
#include <string>
#include <utility>

#include "pch.h"
#include "framework.h"

#include "str_utils.h"
#include "Window.h"
#include "Monitor.h"
namespace utils {
  inline BOOL CALLBACK monitorCallback(HMONITOR hmonitor, HDC hdc, LPRECT lprect, LPARAM lParam) {
    std::vector<std::shared_ptr<i3::Monitor>>& monitors = *reinterpret_cast<std::vector<std::shared_ptr<i3::Monitor>>*>(lParam);
    RECT rect(*lprect);
    // TODO undo this line
    i3::Monitor monitor(hmonitor, rect);
    // monitors.push_back(std::make_shared<i3::Monitor>(hmonitor, rect));
    return TRUE;
  }

  inline std::vector<std::shared_ptr<i3::Monitor>> getMonitors() {
    std::vector<std::shared_ptr<i3::Monitor>> monitors;
    EnumDisplayMonitors(NULL, NULL, monitorCallback, reinterpret_cast<LPARAM>(&monitors));
    return monitors;
  }

  inline BOOL CALLBACK windowCallback(HWND hwnd, LPARAM lParam) {
    const DWORD TITLE_SIZE = 1024;
    WCHAR windowTitle[TITLE_SIZE];

    GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);

    int length = GetWindowTextLength(hwnd);
    std::wstring titleW(&windowTitle[0]);
    if (!IsWindowVisible(hwnd) || length == 0 || titleW == L"Program Manager") {
      return TRUE;
    }

    DWORD pidD = 0;
    GetWindowThreadProcessId(hwnd, &pidD);
    const DWORD dwDesiredAccess = PROCESS_QUERY_LIMITED_INFORMATION;
    const BOOL bInheritHandle = FALSE;
    HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, pidD);

    DWORD nSizeActual = 1000; //for some reason if these values are not equal, fuckery occurs
    const DWORD N_SIZE_MAX = 1000;
    const DWORD dwFlags = 0;
    wchar_t exePathArr[N_SIZE_MAX];
    QueryFullProcessImageNameW(hProcess, dwFlags, exePathArr, &nSizeActual);

    std::wstring exePathW{ exePathArr };
    std::string title{ wstringToString(titleW) };
    std::string fullExePath{ wstringToString(exePathW) };

    int pid = static_cast<int>(pidD);

    // Retrieve the pointer passed into this callback, and re-'type' it.
    // The only way for a C API to pass arbitrary data is by means of a void*.
    std::vector<std::unique_ptr<i3::Window>>& windows =
      *reinterpret_cast<std::vector<std::unique_ptr<i3::Window>>*>(lParam);
    windows.push_back(std::make_unique<i3::Window>(hwnd, title, pid, fullExePath));

    return TRUE;
  }

  inline std::vector<std::unique_ptr<i3::Window>> getOpenWindows() {
    std::vector<std::unique_ptr<i3::Window>> windows;
    EnumWindows(windowCallback, reinterpret_cast<LPARAM>(&windows));
    return windows;
  }

  inline HMONITOR GetPrimaryMonitorHandle(){
    const POINT ptZero = { 0, 0 };
    return MonitorFromPoint(ptZero, MONITOR_DEFAULTTOPRIMARY);
  }

  inline void OnSize(HWND hwnd, UINT flag, int width, int height){
      // Handle resizing
      std::cout << "resize2!!!!" << std::endl;
  }

  // inline LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
  // {
      // switch (uMsg)
      // {
      // case WM_SIZE:
          // {
            // std::cout << "resize!!!!" << std::endl;
              // int width = LOWORD(lParam);  // Macro to get the low-order word.
              // int height = HIWORD(lParam); // Macro to get the high-order word.

              // // Respond to the message:
              // OnSize(hwnd, (UINT)wParam, width, height);
          // }
          // break;
      // }
  // }

}
