#include "DataContainer.h"
#include "Workspace.h"
namespace i3 {
  Workspace::Workspace(int num, std::shared_ptr<DataContainer> parentDataContainer){
    _num = num;
    _parentDataContainer = parentDataContainer;
  }

  void Workspace::setMonitor(std::shared_ptr<Monitor> monitor){
    _monitor = monitor;
  }
}
