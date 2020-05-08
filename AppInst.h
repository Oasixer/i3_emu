#pragma once
#include <vector>
#include <string>

class AppInst
{
public:
  AppInst();
  std::vector<std::wstring> getWindowList();
};

