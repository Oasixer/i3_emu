#include <vector>
#include "pch.h"
#include "framework.h"
#include "AppInst.h"

namespace {
BOOL CALLBACK windowCallback(HWND hwnd, LPARAM lParam) {
  const DWORD TITLE_SIZE = 1024;
  WCHAR windowTitle[TITLE_SIZE];

  GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);

  int length = GetWindowTextLength(hwnd);
  std::wstring title(&windowTitle[0]);
  if (!IsWindowVisible(hwnd) || length == 0 || title == L"Program Manager") {
    return TRUE;
  }

  // Retrieve the pointer passed into this callback, and re-'type' it.
  // The only way for a C API to pass arbitrary data is by means of a void*.
  std::vector<std::wstring>& titles =
    *reinterpret_cast<std::vector<std::wstring>*>(lParam);
  titles.push_back(title);

  return TRUE;
}

  AppInst::AppInst(){
  std::cout << "Init AppInst" << std::endl;
}

std::vector<std::wstring> AppInst::getWindowList(){
  std::vector<std::wstring> titles;
  EnumWindows(windowCallback, reinterpret_cast<LPARAM>(&titles));
  for (const auto& title : titles){
    std::wcout << L"Title: " << title << std::endl;
  }
  std::cin.get();
  return titles;
}
}
