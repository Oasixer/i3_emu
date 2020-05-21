#pragma once
#include <memory>

#include "Composite.h"

namespace i3 {
  class DataContainer;
  class MonitorData;
  class Workspace: public Composite{
    private:
      int _num;
      std::shared_ptr<MonitorData> _monitorData;
      std::shared_ptr<DataContainer> _parentDataContainer;
    public:
      Workspace(int num, std::shared_ptr<DataContainer> parentDataContainer);
      void setMonitor(std::shared_ptr<MonitorData> monitorData);
  };
}
