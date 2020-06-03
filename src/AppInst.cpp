#include <vector>
#include <memory>
#include <iostream>

#include "win32_utils.h"
#include "str_utils.h"

#include "Taskbar.h"
#include "DataContainer.h"
#include "AppInst.h"
namespace i3{
  AppInst::AppInst(){
    std::cout << "Init AppInst" << std::endl;
    _dataContainer = DataContainer("./save");
    // _dataContainer.setWindows(utils::getOpenWindows());
    _dataContainer.setMonitors(utils::getMonitors());
    //_dataContainer.attachApps();
    _dataContainer.createDefaultWorkspaceLayout();
    _dataContainer.applyDefaultWorkspaceLayout();
    //_dataContainer.attachWindowCallbacks();
    gShowHideTaskBar(true); // hide
    Sleep(1000);
    gShowHideTaskBar(false); // show

    std::cout << "Finish init AppInst" << std::endl;
  }

  void AppInst::writeAppsToJson() {
    //_dataContainer.writeAppsToJson();
  }

  std::ostream& operator<<(std::ostream& os, AppInst& appInst)
  {
    os << appInst.getDataContainer();
    return os;
  }
}
