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
#include "cControl.h"
#define CLASS cControl
extern HFONT GLBL_FONT;
CLASS::CLASS(HWND hw,int x,int y,const char* text,const char*data){
  hwnd=hw;
  bounds.left=bounds.right=x;
  bounds.top=bounds.bottom=y;
  Text  = strdup(text);
  if(data)
    Data = strdup(data);
  else
    Data = NULL;
  State.enabled = true;
  State.index=0;
  setWH(text);  
}

CLASS::~CLASS(){
  free(Text);
}

void CLASS::Enable(bool val){
  State.enabled=val;
  ForceRedraw();
}

bool CLASS::isIn(int x,int y){
  if( (x>=bounds.left) && (y>=bounds.top)  && x<bounds.right && y<bounds.bottom )
    return TRUE;
  else
    return FALSE; 
}

void CLASS::setWH(const char*text){
  HDC hdc = GetDC(hwnd);
 	SelectObject(hdc, GLBL_FONT);
	 SIZE sz;
  GetTextExtentPoint32(hdc,text,strlen(text),&sz);
  ReleaseDC(hwnd,hdc);
  int i =bounds.left+sz.cx;
  if(bounds.right<i) bounds.right=i;
  i = bounds.top+sz.cy;
  if(bounds.bottom <i) bounds.bottom=i;
}

void CLASS::ForceRedraw(){
  InvalidateRect(hwnd,&bounds,TRUE);
}
