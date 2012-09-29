#pragma once
#include "cControl.h"
class cCtlCheckBox:public cControl {
public:
  cCtlCheckBox(HWND hwnd,U32 x,U32 y,const char* text,const char*data=NULL);
  ~cCtlCheckBox();
  virtual void draw(HDC hdc);
  virtual void onLButtonDown();
  virtual const char* getData();      //return data string
 } ;
