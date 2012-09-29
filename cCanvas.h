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