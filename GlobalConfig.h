#pragma once
#include "rapidjson/document.h"

namespace i3{
class GlobalConfig
{
public:
  GlobalConfig();
  GlobalConfig(rapidjson::Document *d);
  // keybinds later
};
}
