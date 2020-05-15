#pragma once
#include <memory>
#include <vector>
#include <string>

#include "pch.h"
#include "framework.h"

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

  DWORD nSizeActual = 1000; //for some reason if these values are not equal, fuckery occurs
  const DWORD N_SIZE_MAX = 1000;
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
  std::vector<std::wstring> newInfo {title, exePath, pidStr};
  info.push_back(newInfo);

  return TRUE;
}

inline std::unique_ptr<std::vector<std::vector<std::wstring> > > getOpenWindowVecs(){
  std::vector<std::vector<std::wstring> > windowVecs;
  EnumWindows(windowCallback, reinterpret_cast<LPARAM>(&windowVecs));
  for (const auto& windowVec : windowVecs){
    //std::wcout << L"Title: " << windowVec[0] << std::endl;
    //std::wcout << L"Path: " << windowVec[1] << std::endl;
  }
  // auto windowsPtr(std::make_unique<std::vector<std::vector<std::wstring> > >);
  return std::make_unique<std::vector<std::vector<std::wstring> > >(windowVecs);
}
