#include <vector>
#include "pch.h"
#include "framework.h"

#include "boost_utils.hpp"
#include "DataContainer.h"
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

  // int pidStr = std::stoi(); // convert to int
  // std::wstring ws2 = std::to_wstring(i); // and back to wstring
  std::wstring pidStr = std::to_wstring(static_cast<int>(pid));

  // Retrieve the pointer passed into this callback, and re-'type' it.
  // The only way for a C API to pass arbitrary data is by means of a void*.
  std::vector<std::vector<std::wstring> >& info =
    *reinterpret_cast<std::vector<std::vector<std::wstring> >*>(lParam);
  std::vector<std::wstring> newInfo = {title, exePath, pidStr};
  info.push_back(newInfo);

  return TRUE;
}

namespace i3{


AppInst::AppInst(){
  std::cout << "Init AppInst" << std::endl;
  DataContainer dataContainer("./save");
  auto vecPtr = getOpenWindowVec();
  dataContainer.parseOpenWindowsFromVec(vecPtr);
}

void AppInst::buildObjectsFromFiles() {
    //listFiles();
}
std::vector<std::vector<std::wstring> >* AppInst::getOpenWindowVec(){
  std::vector<std::vector<std::wstring> > windows;
  EnumWindows(windowCallback, reinterpret_cast<LPARAM>(&windows));
  for (const auto& window : windows){
    std::wcout << L"Title: " << window[0] << std::endl;
    std::wcout << L"Path: " << window[1] << std::endl;
  }
  return &windows;
}

void AppInst::setActiveWindow(int id){
}
}
