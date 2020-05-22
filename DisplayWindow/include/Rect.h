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

      Rect(HWND hwnd);

      void setFromRECT(RECT& rect){
        _top = static_cast<int>(rect.top);
        _right = static_cast<int>(rect.right);
        _bottom = static_cast<int>(rect.bottom);
        _left = static_cast<int>(rect.left);
      }
      
      Rect(RECT rect){
        setFromRECT(rect);
      }

      void setTop(int top_){
        _top=top_;
      }

      void mvTop(int top_){
        _top+=top_;
      }
      void mvRight(int right){
        _right+=right;
      }
      void mvBottom(int bottom){
        _bottom += bottom;
      }
      void mvLeft(int left){
        _left += left;
      }

      int getTop(){ return _top; };
      int getRight(){ return _right; };
      int getBottom(){ return _bottom; };
      int getLeft(){ return _left; };
      
      RECT getRECT(){
        RECT rect;
        rect.left = static_cast<LONG>(_left);
        rect.top = static_cast<LONG>(_top);
        rect.bottom = static_cast<LONG>(_bottom);
        rect.right = static_cast<LONG>(_right); 
        return rect;
      }
  };
}
