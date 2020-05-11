#pragma once
#include <vector>
#include <string>

class Window
{
public:
  Window();
  int workspace;
  // Workspace* workspacePtr;
  // App* appPtr;
  // exePath should go in the App container
  // std::wstring exePath;
  std::wstring title;
  int pid;
};

