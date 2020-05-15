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
      // void setActiveWindow(int id);
      // void buildObjectsFromFiles();
  };
}
