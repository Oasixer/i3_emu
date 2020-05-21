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
  class DataContainer: public std::enable_shared_from_this<DataContainer>
  {
    private:
      std::vector<std::shared_ptr<App> > apps;
      std::shared_ptr<GlobalConfig> globalConfig;
      std::vector<std::shared_ptr<Workspace> > workspaces;
    public:
      DataContainer();
      DataContainer(std::string pathToSaveDir);
      const std::shared_ptr<DataContainer> getptr() { return shared_from_this(); }
      std::unique_ptr<std::vector<std::shared_ptr<App> > > getApps(){
       return std::make_unique<std::vector<std::shared_ptr<App> > >(apps); 
      };
      std::shared_ptr<App> findAppByNameOrCreateNewIfNeeded(std::string name, std::vector<std::wstring> vec);
      void parseOpenWindowsFromVec(std::unique_ptr<std::vector<std::pair<HWND, std::vector<std::wstring> > > > vec);
      void writeAppsToJson();
      void CreateWorkspaceLayout();
      friend std::ostream& operator<<(std::ostream& os, const DataContainer& dc);
  };
}
