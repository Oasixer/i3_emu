#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

class DataContainer;
namespace i3{
  class AppInst{
    private:
      std::shared_ptr<DataContainer> dataContainer;
    public:
      AppInst();
      const DataContainer& getDataContainer();
      friend std::ostream& operator<<(std::ostream& os, AppInst appInst);
  };
}
