#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

namespace i3{
  class DataContainer;
  class AppInst{
    private:
      std::shared_ptr<DataContainer> _dataContainer;
    public:
      AppInst();
      const DataContainer& getDataContainer() const {
        return *_dataContainer;
      }
      void writeAppsToJson() const;
      friend std::ostream& operator<<(std::ostream& os, AppInst& appInst);
  };
}
