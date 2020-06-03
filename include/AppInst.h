#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "DataContainer.h"
namespace i3{
  class AppInst{
    private:
      DataContainer _dataContainer;
    public:
      AppInst();
      DataContainer& getDataContainer(){
        return _dataContainer;
      }
      void writeAppsToJson();
      friend std::ostream& operator<<(std::ostream& os, AppInst& appInst);
  };
}
