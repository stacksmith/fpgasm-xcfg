/******************************************************************************
 Copyright 2012 Victor Yurkovsky

    This file is part of xcfg

    xcfg is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    xcfg is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with xcfg.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/
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
