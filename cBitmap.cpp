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
#include "cBitmap.h"
#define CLASS cBitmap
extern HINSTANCE hInst;
/******************************************************************************
Constructors, etc.
 
******************************************************************************/
CLASS::CLASS() {
  _hBitmap=0;
}

CLASS::CLASS(cBitmap& other){
  _hBitmap = other._hBitmap;  
 }
CLASS::CLASS(HBITMAP hbm){
  _hBitmap = hbm;  
 }
CLASS::~CLASS(){
  Free();
}

CLASS::operator HBITMAP(){
  return _hBitmap;
}

void CLASS::Free(){
  if(_hBitmap){
    DeleteObject(_hBitmap);
    _hBitmap=0;
  }
}  
 /******************************************************************************
GetSize 
******************************************************************************/
void CLASS::GetSize (SIZE& size){
    BITMAP bm;
    ::GetObject (_hBitmap, sizeof (bm), & bm);
    size.cx = bm.bmWidth;
    size.cy= bm.bmHeight;
}

/******************************************************************************
Load from file
 
******************************************************************************/
void CLASS::Load(const char * resName){
  Free();
  _hBitmap = (HBITMAP)::LoadImage(hInst, resName,
    IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
  if(!_hBitmap){
    fprintf(stderr,"Can't load bitmap from resources\n");
  }
}

void CLASS::Load(int id){
  Free();
  _hBitmap = (HBITMAP)::LoadImage(hInst, MAKEINTRESOURCE(id),
    IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION);
  if(!_hBitmap)
    fprintf(stderr,"Can't load bitmap from resources\n");
}
