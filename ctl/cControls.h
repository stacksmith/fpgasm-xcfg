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
