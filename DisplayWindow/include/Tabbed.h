#pragma once
#include <memory>

#include "Composite.h"

namespace i3 {
  class Tabbed: public Composite{
    private:
      std::shared_ptr<Composite> _parent;
    public:
      Tabbed(std::shared_ptr<Composite> parent);
  };
}
