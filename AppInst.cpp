#include <vector>
#include "pch.h"
#include "framework.h"
#include "AppInst.h"

BOOL CALLBACK windowCallback(HWND hwnd, LPARAM lParam) {
  const DWORD TITLE_SIZE = 1024;
  WCHAR windowTitle[TITLE_SIZE];

  GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);

  int length = GetWindowTextLength(hwnd);
  std::wstring title(&windowTitle[0]);
  if (!IsWindowVisible(hwnd) || length == 0 || title == L"Program Manager") {
    return TRUE;
  }

  DWORD pid = 0;
  GetWindowThreadProcessId(hwnd, &pid);
  const DWORD dwDesiredAccess = PROCESS_QUERY_LIMITED_INFORMATION;
  const BOOL bInheritHandle = FALSE;
  HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, pid);

  DWORD nSizeActual = 0;
  const DWORD N_SIZE_MAX = 4000;
  const DWORD dwFlags = 0;
  wchar_t exePathArr[N_SIZE_MAX];
  QueryFullProcessImageNameW(hProcess, dwFlags, exePathArr, &nSizeActual);
  std::wstring exePath(exePathArr);

  // Retrieve the pointer passed into this callback, and re-'type' it.
  // The only way for a C API to pass arbitrary data is by means of a void*.
  std::vector<std::vector<std::wstring> >& info =
    *reinterpret_cast<std::vector<std::vector<std::wstring> >*>(lParam);
  std::vector<std::wstring> newInfo = {title, exePath};
  info.push_back(newInfo);

  return TRUE;
}

AppInst::AppInst(){
  std::cout << "Init AppInst" << std::endl;
}

std::vector<std::vector<std::wstring> > AppInst::getWindowList(){
  std::vector<std::vector<std::wstring> > windows;
  EnumWindows(windowCallback, reinterpret_cast<LPARAM>(&windows));
  for (const auto& window : windows){
    std::wcout << L"Title: " << window[0] << std::endl;
    std::wcout << L"Path: " << window[1] << std::endl;
  }
  // std::cin.get();
  return windows;
}

// void AppInst::fgWinName() {
  // HWND hwnd = GetForegroundWindow();
  // DWORD pid = 0;
  // GetWindowThreadProcessId(hwnd, &pid);
  // WINDOWINFO winfo;
  // // GetWindowInfo(hwnd, &winfo);
  // DWORD dwDesiredAccess = PROCESS_QUERY_LIMITED_INFORMATION;
  // BOOL bInheritHandle = FALSE;
  // HANDLE hProcess = OpenProcess(dwDesiredAccess, bInheritHandle, pid);

  // DWORD nSize = 2000;
  // const DWORD dwFlags = 0;
  // wchar_t _name[2000];
  // QueryFullProcessImageNameW(hProcess, dwFlags, _name, &nSize);
  // std::wstring name(_name);
// }

void AppInst::setActiveWindow(int id){
}
