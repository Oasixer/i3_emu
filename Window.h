#pragma once
#include <vector>
#include <string>
#include <memory>

//#include "Workspace.h"

//#include "App.h"

namespace i3{
  class App;
  class Window
  {
    private:
      int wsNum;
      //Workspace *workspacePtr;
      std::shared_ptr<App> appPtr;
      std::string title;
      int pid;
    public:
      Window(int ws, std::string title, int pid);

      void setAppPtr(std::shared_ptr<App> appPtr);
  };
}
