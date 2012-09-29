#pragma once
#include "ctl/cControls.h"
class cSliceM:public cControls{
public:
  cSliceM(HWND hwnd);
  ~cSliceM();
  void Output(FILE* f);
};