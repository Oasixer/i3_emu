#pragma once
#include <memory>

namespace i3{
  class Composite;
  class Component : public std::enable_shared_from_this<Component>
  {
  private:
    int _top;
    int _left;
    int _bottom;
    int _right;
    std::shared_ptr<Composite> _parent;
  public:
    // virtual void traverse() = 0;
    void resize(int newTop, int newLeft, int newBottom, int newRight);
    const std::shared_ptr<Component> getptr() { return shared_from_this(); }
    void setParent(std::shared_ptr<Composite> parent);
  };
}
