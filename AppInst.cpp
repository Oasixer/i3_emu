#include <vector>
#include <memory>

// #include "boost_utils.h"
#include "win32_utils.h"
#include "DataContainer.h"

#include "str_utils.h"
#include "AppInst.h"


namespace i3{
  AppInst::AppInst(){
    std::cout << "Init AppInst" << std::endl;
    dataContainer = std::make_shared<DataContainer>("./save");
    auto vecPtr = getOpenWindowVecs();
    dataContainer -> parseOpenWindowsFromVec(std::move(vecPtr));
  }

  // void AppInst::buildObjectsFromFiles() {
    //listFiles();
    // return;
  // }

  // void AppInst::setActiveWindow(int id){
    // return;
  // }
}
