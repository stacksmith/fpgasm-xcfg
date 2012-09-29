#pragma once
#include "cControl.h"
class cControls {
public:
  cControls(HWND hwnd,U32 max);
  ~cControls();
  void draw(HDC hdc);
  cControl* find(U32 x, U32 y);
  void add(cControl* ctl);
protected:
  cControl** controls;
  U32 max;
  U32 index;
};  
