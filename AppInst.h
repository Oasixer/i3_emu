#pragma once
#include <vector>
#include <string>
#include <memory>

namespace i3{
  class DataContainer;
  class AppInst{
    private:
      std::shared_ptr<DataContainer> dataContainer;
    public:
      AppInst();
      // void setActiveWindow(int id);
      // void buildObjectsFromFiles();
  };
}
