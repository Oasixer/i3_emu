#include "Composite.h" 
namespace i3{
  Composite::Composite()
  {}

  Component& Composite::add(std::unique_ptr<Component> ele){
    ele->setParent(this);
    auto& ref = *ele;
    _children.push_back(std::move(ele));
    return ref;
  }

  std::vector<std::unique_ptr<Component>>& Composite::getChildren(){
    return _children;
  };
}
