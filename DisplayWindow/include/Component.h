#pragma once
#include "Rect.h"

namespace i3{
  // class Composite;
  //class Rect;
  class Component{
    protected:
      Rect _rect;
      Component* _parent;
    public:
      // virtual void traverse() = 0;
      Component() {};

      Component(Component* parent);
      void setRect(const Rect& rect);
      Rect& getRect();
      // const auto getptr() { return std::make_unique<Component>(this); }
      void setParent(Component *parent);

      // Component* getLeftSibling();
    };
}
