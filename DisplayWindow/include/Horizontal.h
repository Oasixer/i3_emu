#pragma once
#include <memory>

#include "Composite.h"

namespace i3 {
  class Horizontal: public Composite{
    private:
      std::unique_ptr<Composite> _parent;
    public:
      Horizontal(std::unique_ptr<Composite> parent);
  };
}

