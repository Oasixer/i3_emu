#pragma once
#include <memory>

#include "Composite.h"
namespace i3 {
  class Tabbed: public Composite{
    private:
      int _selected;
    public:
      Tabbed() { };
      Tabbed(Composite *parent);
      int getSelected() const { return _selected; };
      bool setSelected(const int i) { 
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
