#pragma once
#include <vector>
#include <memory>

#include "Component.h"
namespace i3{
  class Composite: public Component {
    protected: //gotta protect your children yo
      std::vector<std::shared_ptr<Component>> _children; // 4. "container" coupled to the interface

    public:
      void add(std::shared_ptr<Component> ele){
        _children.push_back(ele);
      }
      std::vector<std::shared_ptr<Component>>& getChildren() { return _children; };
  };
}
