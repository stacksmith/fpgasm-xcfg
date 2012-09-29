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
#include "cCtlCheckBox.h"
#define CLASS cCtlCheckBox
extern HFONT GLBL_FONT;
CLASS::CLASS(HWND hwnd,U32 x,U32 y,const char* text,const char*data)
: cControl(hwnd, x, y, text,data){
  bounds.right+=13; //room for the checkbox
}


void CLASS::draw(HDC hdc){
// Draw the box
  MoveToEx(hdc, bounds.left, bounds.top+2, NULL);
  LineTo(hdc, bounds.left+10, bounds.top+2);
  LineTo(hdc, bounds.left+10,  bounds.top+12);
  LineTo(hdc, bounds.left,  bounds.top+12);
  LineTo(hdc, bounds.left,  bounds.top+2);
  //state 1? checked
  if(State.index&1){
  MoveToEx( hdc, bounds.left+2, bounds.top+4, NULL);
  LineTo(       hdc, bounds.left+4,  bounds.top+8);
  LineTo(       hdc, bounds.left+10,  bounds.top);
  LineTo(       hdc, bounds.left+11,  bounds.top);
  LineTo(       hdc, bounds.left+4,  bounds.top+9);
  }
  
	SelectObject(hdc, GLBL_FONT);
	SetBkMode(hdc, TRANSPARENT);
  if(State.enabled)
    SetTextColor(hdc, RGB(0,0,0));
  else
    SetTextColor(hdc, RGB(128,128,128));
    
  TextOut( hdc, bounds.left+13,  bounds.top, Text, strlen(Text));

/*  MoveToEx(hdc, bounds.left,  bounds.top,NULL);
  LineTo(hdc, bounds.right, bounds.top);
  LineTo(hdc, bounds.right, bounds.bottom);
  LineTo(hdc, bounds.left,   bounds.bottom);
  LineTo(hdc, bounds.left, bounds.top);
*/  
 }

void CLASS::onLButtonDown(){
if(State.enabled){
    State.index = (State.index +1 ) &1;
    ForceRedraw();
  }
}

const char* CLASS::getData(){
  if(State.index)
    return (const char*) Data;
  else
    return NULL;
}

