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
    dataContainer = std::make_shared<DataContainer>("./save");
    auto windowVecPtr = getOpenWindowVecs();
    auto monitorDataVecPtr = getMonitorDataVec();
    dataContainer -> parseOpenWindowsFromVec(std::move(windowVecPtr));
    dataContainer -> parseMonitorDataFromVec(std::move(monitorDataVecPtr));
    std::cout << "Finish init AppInst" << std::endl;
  }

  const i3::DataContainer& AppInst::getDataContainer(){
    return *dataContainer;
  }

  const void AppInst::writeAppsToJson()
  {
    dataContainer->writeAppsToJson();
  }

  std::ostream& operator<<(std::ostream& os, AppInst& appInst)
  {
    os << appInst.getDataContainer();
    return os;
  }
}
