#pragma once
#include <memory>

#include "framework.h"
#include "pch.h"

namespace i3{
  class MonitorData{
    private:
      std::unique_ptr<HMONITOR> _hmonitor;
      std::unique_ptr<LPRECT> _lprect;
    public:
      MonitorData(HMONITOR hmonitor, LPRECT lprect)
        :_hmonitor{ std::make_unique<HMONITOR>(hmonitor) }
        ,_lprect{ std::make_unique<LPRECT>(lprect) }
      { };
  };
}
