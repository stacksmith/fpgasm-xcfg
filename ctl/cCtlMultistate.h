#pragma once
#include "cControl.h"
class cCtlMultistate:public cControl {
public:
  cCtlMultistate(HWND hwnd,U32 x,U32 y,const char* text,const char*value=NULL);
  ~cCtlMultistate();
  void addState(const char* text,const char*value);
  virtual void draw(HDC hdc);
  virtual void onLButtonDown();
  virtual const char* getData();      //return data string
  
  void nextState();
private:
  char* texts[8];     //texts displayed
  char* values[8];  //values corresponding
  U32 cnt;            //Number of text/value pairs
 } ;
