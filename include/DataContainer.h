#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <utility>

#include "framework.h"
#include "pch.h"

//#include "App.h"
//#include "Monitor.h"
// #include "Workspace.h"
namespace i3 {
  // class App;
  class App;
  class Monitor;
  class GlobalConfig;
  class Window;
  class DataContainer//: public std::enable_shared_from_this<DataContainer>
  {
    private:
      std::vector<std::shared_ptr<App>> _apps; //TODO TEMP put back to unique later
      // std::vector<std::unique_ptr<Window>> _windows;
      // GlobalConfig _globalConfig;
      // std::vector<Workspace> _workspaces;

      // std::vector<std::unique_ptr<Monitor>> _monitors; //TODO TEMP
      std::vector<std::shared_ptr<Monitor>> _monitors;
    public:
      DataContainer();
      DataContainer(std::string pathToSaveDir);
      // const std::shared_ptr<DataContainer> getptr() { return shared_from_this(); }
      std::vector<std::unique_ptr<App>>& getApps();// { return _apps; };
      //std::vector<std::unique_ptr<App>>& getWindows();
      App& findAppByNameOrCreateNewIfNeeded(std::string name, std::string fullExePath);
      // Window* findWindowByHandle(HWND handle);
      Monitor* findMonitorByHandle(HMONITOR handle);
      // void setWindows(std::vector<std::unique_ptr<Window>>& windows);

      // TODO Temp
      // void setMonitors(std::vector<std::unique_ptr<Monitor>>& monitors);
      void setMonitors(std::vector<std::shared_ptr<Monitor>>& monitors);

      // void writeAppsToJson();
      // void attachApps();
      // void attachWindowCallbacks();
      void createDefaultWorkspaceLayout();
      void applyDefaultWorkspaceLayout();
      friend std::ostream& operator<<(std::ostream& os, const DataContainer& dc);
  };
}
