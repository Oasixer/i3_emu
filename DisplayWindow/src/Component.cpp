#include "Composite.h"
#include "Component.h"

namespace i3{
  void Component::resize(int newTop, int newLeft, int newBottom, int newRight){
    _top = newTop;
    _bottom = newBottom;
    _right = newTop;
    _left = newLeft;
  }

  void Component::setParent(std::shared_ptr<Composite> parent){
    _parent = parent;
  }
}
