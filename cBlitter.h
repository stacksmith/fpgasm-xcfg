#pragma once 
#include "cBitmap.h"
#include "cCanvas.h"
class cBlitter{
public:
  cBlitter ();
  void SetMode (DWORD mode){  _mode = mode; }
  void SetDest (int x, int y) { _xDst = x; _yDst = y;  }
  void SetSrc (int x, int y)    { _xSrc = x; _ySrc = y;   }
  void SetArea (int width, int height)   {
        _width = width;
        _height = height;
 }
// transfer bitmap to canvas
void Blit (cCanvas& from,cCanvas & to);

private:
  int     _xDst, _yDst;
  int     _xSrc, _ySrc;
  int     _width, _height;
  DWORD   _mode;
};