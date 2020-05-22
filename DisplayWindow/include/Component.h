#pragma once
#include <memory>

#include "framework.h"
#include "pch.h"

namespace i3{
  class Composite;
  class Component : public std::enable_shared_from_this<Component>
  {
  protected:
    std::shared_ptr<RECT> _rect;
    std::shared_ptr<Composite> _parent;
  public:
    // virtual void traverse() = 0;
    void setRect(RECT& rect) { *_rect = rect; };
    std::shared_ptr<RECT> getRect() { return _rect; };
    const std::shared_ptr<Component> getptr() { return shared_from_this(); }
    void setParent(std::shared_ptr<Composite> parent);
  };
}
