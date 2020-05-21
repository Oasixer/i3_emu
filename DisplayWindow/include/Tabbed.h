#pragma once
#include <memory>

#include "Composite.h"
namespace i3 {
  class Tabbed: public Composite{
    private:
      std::shared_ptr<Composite> _parent;
      int _selected;
    public:
      Tabbed(std::shared_ptr<Composite> parent);
      const int getSelected() const { return _selected; };
      const bool setSelected(int i) { 
        if (i>0 && i < _children.size()){
          _selected=i;
          return true;
        }
        else{
          return false;
        }
      }
  };
}
