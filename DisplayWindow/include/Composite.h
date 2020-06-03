#pragma once
#include <vector>
#include <memory>

#include "Component.h"
namespace i3{
  class Composite: public Component {
    protected: //gotta protect your children yo
      std::vector<std::unique_ptr<Component>> _children; // 4. "container" coupled to the interface

    public:
      Composite();
      Component& add(std::unique_ptr<Component> ele);
      std::vector<std::unique_ptr<Component>>& getChildren();
  };
}
