#pragma once
#include <memory>

#include "Composite.h"
namespace i3 {
  class DataContainer;
  class Monitor;
  class Workspace: public Composite{
    private:
      int _num;
      std::shared_ptr<Monitor> _monitor;
      std::shared_ptr<DataContainer> _parentDataContainer;
    public:
      Workspace(int num, std::shared_ptr<DataContainer> parentDataContainer);
      void setMonitor(std::shared_ptr<Monitor> monitor);
  };
}
