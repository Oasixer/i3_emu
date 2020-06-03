// #include "Component.h"
#include "Rect.h"

namespace i3 {
  Rect::Rect(HWND windowHandle) {
    RECT rect;
    GetWindowRect(windowHandle, &rect);
    setFromRECT(rect);
  }
}
