#pragma once
#include <memory>

#include "rapidjson/document.h"

namespace i3{
  class GlobalConfig{
    private:
    public:
      GlobalConfig();
      GlobalConfig(std::string pathStr);
      // keybinds later
  };
}
