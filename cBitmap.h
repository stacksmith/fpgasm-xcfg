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
class cBitmap {
public:
  cBitmap();
  cBitmap(cBitmap& other);
  cBitmap(HBITMAP hbm);
  ~cBitmap();
  operator HBITMAP();
  void GetSize (SIZE& size);
  void Load(const char * resName); 
  void Load(int id);
protected:
  void Free();
  
//DATA:
  HBITMAP _hBitmap;

};