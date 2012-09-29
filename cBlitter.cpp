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
#define CLASS cBlitter
extern HINSTANCE hInst;
/******************************************************************************
Constructors, etc.
 
******************************************************************************/
CLASS::CLASS(){
  _mode = SRCCOPY;
  _xDst = _yDst = 0;
  _xSrc = _ySrc = 0;
  _width = _height=0;
}

/******************************************************************************
Blit 
******************************************************************************/
void CLASS::Blit (cCanvas& from, cCanvas& to){
/*  // Create canvas in memory using target canvas as template
  cMemCanvas memCanvas (canvas);
  // Convert bitmap to the format appropriate for this canvas
  memCanvas.SelectObject (_cbm); //convertible to HBITMAP
  // Transfer bitmap from memory canvas to target canvas
  ::BitBlt (canvas, _xDst, _yDst, _width, _height, 
    memCanvas, _xSrc, _ySrc, _mode);
*/}


 