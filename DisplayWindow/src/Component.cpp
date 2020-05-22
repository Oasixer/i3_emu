#include "Composite.h"
#include "Component.h"

namespace i3{
  void Component::setParent(std::shared_ptr<Composite> parent){
    _parent = parent;
  }
}
