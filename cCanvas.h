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
class cCanvas{
public:
  operator HDC () { return _hdc; }
  void Point (int x, int y, COLORREF color) {  ::SetPixel (_hdc, x, y, color);}
  void MoveTo (int x, int y) {  ::MoveToEx (_hdc, x, y, 0);}
  void LineTo(int x, int y) { ::LineTo(_hdc, x, y);}
  void Line ( int x1, int y1, int x2, int y2 ); 
  void Rectangle (int left, int top, int right, int bottom){
      ::Rectangle (_hdc, left, top, right, bottom);
  }
  void GetTextSize (int & cxChar, int & cyChar) ;
  void Text (int x, int y, char const * buf, int cBuf) {
      ::TextOut ( _hdc, x, y, buf, cBuf );
  }
  void Char (int x, int y, char c){
      ::TextOut (_hdc, x, y, & c, 1);
  }
  void* SelectObject (void* pObj){
    return ::SelectObject (_hdc, pObj);
  }
  bool BitBlt(HDC from, POINT& sxy, SIZE& wh , POINT&dxy, U32 rop=SRCCOPY);
 
protected:
  cCanvas (HDC hdc);
//DATA
protected:
    HDC  _hdc;
};

class cPaintCanvas: public cCanvas{
public:
    cPaintCanvas (HWND hwnd);
    ~cPaintCanvas ();
protected:
    PAINTSTRUCT _paint;
    HWND        _hwnd;
};

class cMemCanvas: public cCanvas{
public:
    cMemCanvas(cCanvas &canvas);
    ~cMemCanvas ();
protected:
};