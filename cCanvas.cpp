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
#include "cCanvas.h"
#define CLASS cCanvas
extern HINSTANCE hInst;
/******************************************************************************
Constructors, etc.
 
******************************************************************************/
CLASS::CLASS(HDC hdc){
  _hdc=hdc;
}
/******************************************************************************
 
******************************************************************************/
void CLASS::Line ( int x1, int y1, int x2, int y2 ) {
  MoveToEx (_hdc, x1, y1, 0);
  ::LineTo (_hdc, x2, y2);
}

void CLASS::GetTextSize (int & cxChar, int & cyChar) {
    TEXTMETRIC tm;
    GetTextMetrics (_hdc, & tm);
    cxChar = tm.tmAveCharWidth;
    cyChar = tm.tmHeight + tm.tmExternalLeading;
}

/******************************************************************************
Blit, with slightly saner parameters

******************************************************************************/
bool  CLASS::BitBlt(HDC from, POINT& sxy, SIZE& wh , POINT&dxy, U32 rop){
  return ::BitBlt(_hdc, 
    dxy.x , dxy.y,  wh.cx, wh.cy,
    from, sxy.x, sxy.y,
    rop);
}


/******************************************************************************
******************************************************************************
******************************************************************************
*****************************************************************************/
/******************************************************************************
 cPaintCanvas is created in WM_PAINT and represents the DC from BeginPaint. 
******************************************************************************/
cPaintCanvas::cPaintCanvas(HWND hwnd)
  :cCanvas(::BeginPaint(hwnd,&_paint)) //base class constructed from this
{
  _hwnd = hwnd;
}

cPaintCanvas::~cPaintCanvas(){
  ::EndPaint(_hwnd,&_paint);
}
/******************************************************************************
******************************************************************************
******************************************************************************
 Memory-based DC canvas
*****************************************************************************/
cMemCanvas::cMemCanvas(cCanvas &likeThis)
  :cCanvas(::CreateCompatibleDC(likeThis))
{
}
cMemCanvas::~cMemCanvas(){
  ::DeleteDC(_hdc);
}