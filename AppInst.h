#pragma once
#include <vector>
#include <string>

//#include "DataContainer.h"

namespace i3{
    class DataContainer;
class AppInst
{
    DataContainer* dataContainer;
public:
  AppInst();
  std::vector<std::vector<std::wstring> >* getOpenWindowVec();
  void setActiveWindow(int id);
  void buildObjectsFromFiles();

  
};
}
