#pragma once
#include <vector>
#include <string>
#include <memory>

class DataContainer;
namespace i3{
  class AppInst{
    private:
      std::shared_ptr<DataContainer> dataContainer;
    public:
      AppInst();
      std::shared_ptr<DataContainer> getDataContainer() { return dataContainer; };
  };
}
