#include "Component.h"

namespace i3{
  void Component::resize(int newTop, int newLeft, int newBottom, int newRight){
    _top = newTop;
    _bottom = newBottom;
    _right = newTop;
    _left = newLeft;
  }
}
