#include "Rect.h"
#include "Composite.h"
#include "Component.h"

namespace i3{
  Component::Component(Component* parent){
    _parent = parent;
  } 

  void Component::setParent(Component* parent){
    _parent = parent;
  }
  
  void Component::setRect(const Rect& rect){
    _rect = rect;
  }

  Rect& Component::getRect(){
    return _rect;
  }

  // Component* Component::getLeftSibling() {
    // if (_parent == nullptr) {
      // return nullptr;
    // }
    // auto& parentsChildren = _parent->getChildren();
    //auto i = find_if(begin(parentsChildren), end(parentsChildren),
    //    [&](const unique_ptr<Component>& node){ return node.get() == this; });
    // TODO; figure out what type i is


    //TODO: getRightSibling()
    // return nullptr; //TEMP so it compiles
  // }
}
