#include <vector>
#include <memory>

#include "boost_utils.hpp"
#include "win32_utils.hpp"
#include "DataContainer.h"
#include "AppInst.h"


namespace i3{
  AppInst::AppInst(){
    std::cout << "Init AppInst" << std::endl;
    dataContainer = std::make_unique<DataContainer>("./save");
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
