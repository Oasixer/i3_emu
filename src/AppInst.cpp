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
    _dataContainer->attachWindowCallbacks();
    //std::string temp;
    //std::cin >> temp;
    // std::cout << (*(_dataContainer->getWindows()))[0]->getRect()->bottom << std::endl;
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
