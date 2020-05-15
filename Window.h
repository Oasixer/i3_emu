#pragma once
#include <vector>
#include <string>
#include <memory>

#include "str_utils.h"

//#include "Workspace.h"

//#include "App.h"

namespace i3{
class App;
class Window
{
  private:
    int workspace;
    //Workspace *workspacePtr;
    std::shared_ptr<App> appPtr;
    std::string title;
    int pid;
  public:
    Window(int ws, std::string title, int pid);//, std::shared_ptr<App> appPtr);
      // : workspace(ws) // TODO
      // , title(title)
      // , appPtr(appPtr)
      // , pid(pid)
    // { }

    void setAppPtr(std::shared_ptr<App> appPtr);//{appPtr=appPtr;}
};
}
