#pragma once
#include <memory>

#include "framework.h"
#include "pch.h"

#include "Rect.h"

namespace i3{
  class Monitor{
    private:
      const HMONITOR _handle;
      std::shared_ptr<Rect> _rect;
    public:
      Monitor(HMONITOR handle, RECT rect)
        :_handle{ handle }
        ,_rect{ std::make_shared<Rect>(rect) }
      { };
      const HMONITOR getHandle() const { return _handle; };
  };
}
