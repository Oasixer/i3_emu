#pragma once
#include <memory>

#include "Composite.h"

namespace i3 {
  class Vertical: public Composite{
    private:
      std::unique_ptr<Composite> _parent;
    public:
      Vertical(std::unique_ptr<Composite> parent);
  };
}
