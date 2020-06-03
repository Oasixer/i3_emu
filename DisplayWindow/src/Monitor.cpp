#include "Monitor.h"

namespace i3{
  Monitor::Monitor(HMONITOR handle, RECT rect){
    _rect = Rect(rect);
    _handle = handle;
    _parent = nullptr;
  }

}
