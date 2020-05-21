#pragma once
#include <memory>

#include "framework.h"
#include "pch.h"

namespace i3{
  class Monitor{
    private:
      std::unique_ptr<HMONITOR> _handle;
      std::unique_ptr<LPRECT> _lprect;
    public:
      Monitor(HMONITOR handle, LPRECT lprect)
        :_handle{ std::make_unique<HMONITOR>(handle) }
        ,_lprect{ std::make_unique<LPRECT>(lprect) }
      { };
      const HMONITOR& getHandle() const {return *_handle; };
  };
}
