#pragma once

#include "framework.h"
#include "pch.h"

namespace i3{
  class Rect{
    private:
      int _top;
      int _right;
      int _bottom;
      int _left;
    public:
      // order: top, right, bottom, left
      Rect(int top_, int right, int bottom, int left)
        :_top{ top_ }
        ,_right{right}
        ,_bottom{bottom}
        ,_left{left}
      { };

      Rect(RECT& rect)
        :_top{static_cast<int>(rect.top)}
        ,_right{static_cast<int>(rect.right)}
        ,_bottom{static_cast<int>(rect.bottom)}
        ,_left{static_cast<int>(rect.left)}

      setFromRECT(RECT& rect){
        _top = rect.top;
        _right = rect.right;
        _bottom = rect.bottom;
        _left = rect.left;
      }
  };
}
