#pragma once
#include <vector>
#include <memory>

#include "Component.h"

namespace i3{
  class Composite: public Component {
    private:
      std::vector<std::shared_ptr<Component> > children; // 4. "container" coupled to the interface

    public:
      void add(std::shared_ptr<Component> ele){
        children.push_back(ele);
      }
      // void traverse();
  };
}
