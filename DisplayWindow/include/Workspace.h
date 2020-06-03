#pragma once
#include <memory>

#include "Composite.h"
namespace i3 {
  class DataContainer;
  // class Monitor;
  class Workspace: public Composite{
    private:
      int _num;
      // Monitor* _monitor; //TODO: check if this would need to be a reference member var - try changing a param and see if it goes through to the original monitor obj
      // DataContainer* _parentDataContainer;
    public:
      Workspace(int num);//, DataContainer* parentDataContainer);
      // void setMonitor(Monitor* monitor);
  };
}
