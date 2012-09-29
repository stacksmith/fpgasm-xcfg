#pragma once
struct sCtlState {
  bool enabled:1;
  U32 index:31;
};
class cControl {
public:
  cControl(HWND hwnd,int x,int y,const char* text,const char*data=NULL);
  ~cControl();
  virtual void draw(HDC hdc)=0;
  virtual void onLButtonDown()=0;
  virtual const char* getData()=0;      //return data string

  bool isIn(int x, int y);
  void ForceRedraw();
  void Enable(bool val);
  bool getEnabled(){return State.enabled;}
  U32 getState(){return State.index;}
protected:
  void setWH(const char*text);
  char* Text;
  char* Data;
  RECT bounds;
  sCtlState State;
  HWND hwnd;
 } ;
