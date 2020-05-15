#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <memory>

namespace i3 {
  class App;
  class GlobalConfig;
  class DataContainer
  {
    private:
      std::vector<std::shared_ptr<App> > apps;
      std::shared_ptr<GlobalConfig> globalConfig;
    public:
      DataContainer();
      DataContainer(std::string pathToSaveDir);
      std::unique_ptr<std::vector<std::shared_ptr<App> > > getApps(){
       return std::make_unique<std::vector<std::shared_ptr<App> > >(apps); 
      };
      std::shared_ptr<App> findAppByNameOrCreateNewIfNeeded(std::string name, std::vector<std::wstring> vec);
      void parseOpenWindowsFromVec(std::unique_ptr<std::vector<std::vector<std::wstring> > > vec);
      void printApps();
      friend std::ostream& operator<<(std::ostream& os, const DataContainer& dc);
  };
}
