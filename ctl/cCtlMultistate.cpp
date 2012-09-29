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
#include "global.h"
#include "cCtlMultistate.h"
#define CLASS cCtlMultistate
extern HFONT GLBL_FONT;
CLASS::CLASS(HWND hwnd,U32 x,U32 y,const char* text,const char*value/*=NULL*/)
: cControl(hwnd, x, y, text){
  cnt=1;
  texts[0]=(char*)text; 
  values[0]=(char*)value;
}
void CLASS::addState(const char* text,const char*value){
  texts[cnt]=strdup(text);
  values[cnt]=strdup(value);
  cnt++;
  setWH(text);
  
}

void CLASS::draw(HDC hdc){
	SelectObject(hdc, GLBL_FONT);
	SetBkMode(hdc, TRANSPARENT);
  if(State.enabled){
    if(State.index) {
      SetTextColor(hdc, RGB(0,0,0));
    } else {
      SetTextColor(hdc,RGB(150,150,255));
    }
  } else {
      SetTextColor(hdc,RGB(128,128,128));
  }
  TextOut( hdc, bounds.left,bounds.top, texts[State.index], strlen(texts[State.index]));

/*  MoveToEx(hdc, bounds.left, bounds.top, NULL);
  LineTo(hdc, bounds.right,  bounds.top);
  LineTo(hdc, bounds.right, bounds.bottom);
  LineTo(hdc, bounds.left,   bounds.bottom);
  LineTo(hdc, bounds.left, bounds.top);
*/}
/******************************************************************************
Multistate controls cycle through states when pressed...

******************************************************************************/

void CLASS::onLButtonDown(){
  if(State.enabled){
    State.index++;
    if(State.index>=cnt){
      State.index=0;
    }
    InvalidateRect(hwnd,&bounds,TRUE); //invalidate my new bounds too
  }
}


const char* CLASS::getData(){
  return (const char*) values[State.index];
}
