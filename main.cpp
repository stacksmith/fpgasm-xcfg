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
#include "ctl/stb_image.h"
#include "cSliceM.h"

//Globals
HINSTANCE hInst;
 HBITMAP bmBk;
 
HFONT GLBL_FONT;
cSliceM* SliceM;

void createBackground(HWND hwnd){
  int w,h, comp;
  U8* data = stbi_load("images\\drawing.jpg",&w,&h,&comp,4);
  U8* bmdata;
// fprintf(stderr,"loaded %p  (%d,%d) %d components\n",data,w,h,comp);
 //Since we have DI data, use CreateDIBSection
  BITMAPINFOHEADER bi;
  bi.biSize = sizeof(BITMAPINFOHEADER);
  bi.biWidth=640;
  bi.biHeight = -480;
  bi.biPlanes = 1;
  bi.biBitCount=32;
  bi.biCompression = BI_RGB;
  bi.biSizeImage = 0;
  bi.biXPelsPerMeter = 0;
  bi.biYPelsPerMeter = 0;
  bi.biClrUsed = 0;
  bi.biClrImportant = 0;
  HDC screenDC = GetDC(0);
  HDC bufferDC = CreateCompatibleDC(screenDC);
   bmBk = CreateDIBSection(
    bufferDC,
    (BITMAPINFO*)&bi,
    DIB_RGB_COLORS,
    (void**)&bmdata,
    NULL,
    0);
    union sPixel {
      U32 value;
      struct sRGB {
        U8 r;
        U8 g;
        U8 b;
        U8 a;
      }rgb;
    };
    DeleteObject(bufferDC);
    ReleaseDC(hwnd,screenDC);
    // We need to reverse r and b positions...
    // memcpy(bmdata,data,640*480*4);
    sPixel* src=(sPixel*)data;
    sPixel* dest=(sPixel*)bmdata;
    int i;
    for(i=0;i<640*480;i++){
      sPixel pixel = *src++;
      U8 t = pixel.rgb.r;
      pixel.rgb.r = pixel.rgb.b;
      pixel.rgb.b = t;
      *dest++ = pixel;
    }
   stbi_image_free(data);
// HBITMAP mybm = CreateBitmap(w,h,1,24,data);
//   fprintf(stderr,"created bitmap %p \n",bmBk);

  
} 
BOOL xcfg_OnCreate(   HWND hwnd, LPCREATESTRUCT lpcs){
  createBackground(hwnd);

  GLBL_FONT = ::CreateFont(
  16, // logical height of font
  0, // logical average char width, 0 = best match
  0, // angle of escapement
  0, // base-line orientation angle
  FW_BOLD, // font weight
  FALSE, // italic attribute flag
  FALSE, // underline attribute flag
  FALSE, // strikeout attribute flag
  DEFAULT_CHARSET, // character set identifier
  OUT_TT_PRECIS, // output preacision; prefer TrueType fonts
  CLIP_DEFAULT_PRECIS, // clipping precision
  ANTIALIASED_QUALITY, // output quality
  FF_SWISS|VARIABLE_PITCH, // pitch and family
  NULL); //any 
  //=============================================================
  // Now, create our controls
  SliceM = new cSliceM(hwnd);
  return TRUE;
}

/******************************************************************************
 OnDestroy
 
******************************************************************************/
void xcfg_OnDestroy(HWND hwnd){
  PostQuitMessage(0);
}
/******************************************************************************
 OnPaint
 
******************************************************************************/
bool FIRSTTIME=true;
void xcfg_OnPaint(  HWND hwnd){
  cPaintCanvas canvas(hwnd);
  cMemCanvas canvMem(/*like*/canvas);
  HGDIOBJ hbmT = canvMem.SelectObject(bmBk);
  BitBlt(canvas,0,0,640,480,canvMem,0,0,SRCCOPY);
  SliceM->draw(canvas);
  SelectBitmap(canvMem,hbmT);
  
 }  
/******************************************************************************
 OnLButtonDown
 
******************************************************************************/
void xcfg_OnLButtonDown(  HWND hwnd,BOOL fDoubleClick, int x, int y, UINT keyFlags){
  cControl* ctrl;
  if((ctrl = SliceM->find(x,y))){
      ctrl->onLButtonDown();
     // MessageBox( NULL, "OK", "XXX",MB_OK|MB_ICONINFORMATION );
   
  } 
}
/******************************************************************************
 OnKeyDown
 
******************************************************************************/
void  xcfg_OnKeyDown(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags){
  if(13==vk){
    SliceM->Output(stdout);
    exit(0);
  }
  fprintf(stdout,"KEY %d\n",vk);
}
/******************************************************************************
Cracker
 
******************************************************************************/
LRESULT CALLBACK xcfg_WindowProc(  HWND hwnd,  UINT uMsg,  WPARAM wParam,  LPARAM lParam){
  switch(uMsg)  {
    HANDLE_MSG(hwnd,WM_CREATE,xcfg_OnCreate);
    HANDLE_MSG(hwnd,WM_DESTROY,xcfg_OnDestroy);
    HANDLE_MSG(hwnd,WM_PAINT,xcfg_OnPaint);
    HANDLE_MSG(hwnd,WM_LBUTTONDOWN,xcfg_OnLButtonDown);
    HANDLE_MSG(hwnd,WM_KEYDOWN,xcfg_OnKeyDown);
  }
  return DefWindowProc(hwnd,uMsg,wParam,lParam);
}  

/******************************************************************************
 RegisterClass
 
******************************************************************************/

void xcfg_RegisterClass( ){
  WNDCLASS wc = {
    0,
    xcfg_WindowProc,
    0,0,
    hInst,
    LoadIcon(NULL,IDI_APPLICATION),
    LoadCursor(NULL,IDC_ARROW),
    (HBRUSH)(COLOR_WINDOW+1),
    NULL,
    "xcfg"
  };
  RegisterClass(&wc);
}


/******************************************************************************
WinMain
 
******************************************************************************/

#define _WIN32_WINNT 0x0501
#include "fcntl.h"
HANDLE hStdout,hStdin;
int WINAPI WinMain(
  HINSTANCE hInstThis,
  HINSTANCE hInstPrev,
  LPSTR lpszCmdLine,
  int nCmdShow)
{
  fprintf(stderr,"--%s\n",lpszCmdLine);
  hInst = hInstThis;  //set the global
  xcfg_RegisterClass();
  
  HWND hwnd = CreateWindowEx(
    0L,
    "xcfg","Xilinx Spartan3 primitive configuration editor",
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, 0, 640, 480,
    HWND_DESKTOP,NULL,hInst,NULL);
    
  ShowWindow(hwnd,nCmdShow);
  UpdateWindow(hwnd);
  
  MSG msg;
  while(GetMessage(&msg,0,0,0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.wParam;
}
