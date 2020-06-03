#pragma once
#include <memory>

#include "framework.h"
#include "pch.h"

#include "Composite.h"
namespace i3{
  class Monitor : public Composite{
    private:
      HMONITOR _handle;
    public:
      Monitor(HMONITOR handle, RECT rect);
      HMONITOR getHandle() const { return _handle; };
  };
}
