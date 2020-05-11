#pragma once
#include <vector>
#include <string>

class AppInst
{
public:
  AppInst();
  std::vector<std::vector<std::wstring> > getWindowList();
  void setActiveWindow(int id);
  void buildObjectsFromFiles();
};

