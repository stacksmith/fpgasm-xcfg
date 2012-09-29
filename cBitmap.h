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