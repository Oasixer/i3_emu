#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <utility>

#include "framework.h"
#include "pch.h"

#include "Workspace.h"

namespace i3 {
  class App;
  class GlobalConfig;
  class Monitor;
  class Window;
  class DataContainer: public std::enable_shared_from_this<DataContainer>
  {
    private:
      std::vector<std::shared_ptr<App>> _apps;
      std::vector<std::shared_ptr<Window>> _windows;
      std::shared_ptr<GlobalConfig> _globalConfig;
      std::vector<std::shared_ptr<Workspace>> _workspaces;
      std::vector<std::shared_ptr<Monitor>> _monitors;
    public:
      DataContainer();
      DataContainer(std::string pathToSaveDir);
      const std::shared_ptr<DataContainer> getptr() { return shared_from_this(); }
      std::unique_ptr<std::vector<std::shared_ptr<App> > > getApps(){
       return std::make_unique<std::vector<std::shared_ptr<App> > >(_apps); 
      };
      std::shared_ptr<App> findAppByNameOrCreateNewIfNeeded(std::string name, std::string fullExePath);
      std::shared_ptr<Window> findWindowByHandle(HWND handle);
      std::shared_ptr<Monitor> findMonitorByHandle(HMONITOR handle);
      std::unique_ptr<std::vector<std::shared_ptr<Window>>> getWindows() {return std::make_unique<std::vector<std::shared_ptr<Window>>>(_windows);};
      void setWindows(std::unique_ptr<std::vector<std::shared_ptr<Window>>> windows);
      void setMonitors(std::unique_ptr<std::vector<std::shared_ptr<Monitor>>> monitors);
      void writeAppsToJson();
      void attachApps();
      void createDefaultWorkspaceLayout();
      void applyDefaultWorkspaceLayout();
      friend std::ostream& operator<<(std::ostream& os, const DataContainer& dc);
  };
}
