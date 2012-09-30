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
struct sCtlState {
  bool enabled:1;
  U32 index:31;
};
class cControl {
public:
  cControl(HWND hwnd,int x,int y,const char* text,const char*data=NULL);
  ~cControl();
  virtual void draw(HDC hdc)=0;
  virtual void onLButtonDown()=0;
  virtual const char* getData()=0;      //return data string

  bool isIn(int x, int y);
  void ForceRedraw();
  void Enable(bool val);
  bool getEnabled(){return State.enabled;}
  U32 getState(){return State.index;}
protected:
  void setWH(const char*text);
  char* Text;
  char* Data;
  RECT bounds;
  sCtlState State;
  HWND hwnd;
 } ;
