#include <vector>
#include <memory>
#include <iostream>

#include "win32_utils.h"
#include "DataContainer.h"

#include "str_utils.h"
#include "AppInst.h"

namespace i3{
  AppInst::AppInst(){
    std::cout << "Init AppInst" << std::endl;
    _dataContainer = std::make_shared<DataContainer>("./save");
    _dataContainer->setWindows(std::move(utils::getOpenWindows()));
    _dataContainer->setMonitors(std::move(utils::getMonitors()));
    _dataContainer->attachApps();
    _dataContainer->createDefaultWorkspaceLayout();
    _dataContainer->applyDefaultWorkspaceLayout();
   
    // SIZE size{ 100,100 };
    RECT rect{ 10, 10, 100, 100 };

    std::cout << (*(_dataContainer->getWindows()))[0]->getRect()->top << std::endl;
    std::cout << (*(_dataContainer->getWindows()))[0]->getRect()->bottom << std::endl;
    (*(_dataContainer->getWindows()))[0]->setRect(rect);
    std::cout << (*(_dataContainer->getWindows()))[0]->getRect()->top << std::endl;
    std::cout << (*(_dataContainer->getWindows()))[0]->getRect()->bottom << std::endl;
    std::cout << "Finish init AppInst" << std::endl;
  }



  void AppInst::writeAppsToJson() const{
    _dataContainer->writeAppsToJson();
  }

  std::ostream& operator<<(std::ostream& os, AppInst& appInst)
  {
    os << appInst.getDataContainer();
    return os;
  }
}
