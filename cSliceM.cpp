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
/******************************************************************************

*****************************************************************************/
#include "global.h"
#include "cSliceM.h"
#include "ctl/cCtlMultistate.h"
#include "ctl/cCtlCheckBox.h"
#define CLASS cSliceM

CLASS::CLASS(HWND hwnd)
  :cControls(hwnd,256)  //Todo: fewer than that
  {

#define XINPUT 25
#define XLUT 100
#define Y0 175
#define Y1 75
#define H 16
  cCtlMultistate* pcm;
  pcm = new cCtlMultistate(hwnd,  XINPUT,    Y0, "BY...");
  pcm->addState("BY","BYINV:BY");
  pcm->addState("~BY","BYINV:BY_B");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XINPUT,    Y0+2*H,    "CE...");
  pcm->addState("CE","CEINV:CE");
  pcm->addState("~CE","CEINV:CE_B");
  add(pcm);
  pcm = new cCtlMultistate(hwnd,  XINPUT,    Y0+3*H,  "CLK...");
  pcm->addState("CLK","CLKINV:CLK");
  pcm->addState("~CLK","CLKINV:CLK_B");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XINPUT,    Y0+4*H,    "SR...");
  pcm->addState("SR","SRINV:SR");
  pcm->addState("~SR","SRINV:SR_B");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XINPUT,    Y0+6*H,    "BX...");
  pcm->addState("BX","BXINV:BX");
  pcm->addState("~BX","BXINV:BX_B");
  add(pcm);
  // 2nd column is for lut/ram setup
  // G Lut type
  #define Y_G_LUT 45
  pcm=new cCtlMultistate(hwnd,  XLUT,   Y_G_LUT,       "G: Unused");
  pcm->addState("LUT","G:#LUT:D=0");
  pcm->addState("RAM","G:#RAM:D=0");
  pcm->addState("ROM","G:#ROM:D=0");
  add(pcm);
  add(pcm);
  // G Lut attributes
  #define Y_G_ATTR 63
  pcm=new cCtlMultistate(hwnd,  XLUT,    Y_G_ATTR,    "G Attr");
  pcm->addState("Dual-port","G_ATTR:DUAL_PORT");
  pcm->addState("Shift register","G_ATTR:SHIFT_REG");
  add(pcm);
  // G Lut WG inputs
  #define Y_WG 85
  cCtlCheckBox *cb;
  cb=new cCtlCheckBox(hwnd,XLUT,Y_WG+0*H,"WG1","WG1USED:0");
  add(cb);
  cb=new cCtlCheckBox(hwnd,XLUT,Y_WG+1*H,"WG2","WG2USED:0");
  add(cb);
  cb=new cCtlCheckBox(hwnd,XLUT,Y_WG+2*H,"WG3","WG3USED:0");
  add(cb);
  cb=new cCtlCheckBox(hwnd,XLUT,Y_WG+3*H,"WG4","WG4USED:0");
  add(cb);
  // DIG mux - shift-in, altdig, by or disabled
  #define Y_SLICEWE 200
  cb=new cCtlCheckBox(hwnd,XLUT,Y_SLICEWE+0*H,"SLICEW0","SLICEW0USED:0");
  add(cb);
  cb=new cCtlCheckBox(hwnd,XLUT,Y_SLICEWE+1*H,"SLICEW1","SLICEWE1USED:0");
  add(cb);

  // DIG mux - shift-in, altdig, by or disabled
  #define Y_DIGMUX 235
  pcm = new cCtlMultistate(hwnd,XLUT,Y_DIGMUX+0*H,"DIGMUX"); //i  n off state, nothing.
  pcm->Enable(true);
  pcm->addState("DIGMUX:SHIFT_IN","DIGMUX:SHIFT_IN");
  pcm->addState("DIGMUX:ALTDIG","DIGMUX:ALTDIG");
  pcm->addState("DIGMUX:BY","DIGMUX:BY");
  add(pcm);
  // F Lut type
  #define Y_FLUT (280)
  pcm=new cCtlMultistate(hwnd,  XLUT,   Y_FLUT+0*H,    "F: Unused");
  pcm->addState("LUT","F:#LUT:D=0");
  pcm->addState("RAM","F:#RAM:D=0");
  pcm->addState("ROM","F:#ROM:D=0");
  add(pcm);
  // F Lut attributes
  #define Y_F_ATTR 298
  pcm=new cCtlMultistate(hwnd,  XLUT,    Y_F_ATTR +0*H,    "F Attr");
  pcm->addState("Dual-port","G_ATTR:DUAL_PORT");
  pcm->addState("Shift register","G_ATTR:SHIFT_REG");
  add(pcm);
 // F LUT WF inputs
  #define Y_WF 320
  cb=new cCtlCheckBox(hwnd,XLUT,Y_WF+0*H,"WF1","WF1USED:0");
  add(cb);
  cb=new cCtlCheckBox(hwnd,XLUT,Y_WF+1*H,"WF2","WF2USED:0");
  add(cb);
  cb=new cCtlCheckBox(hwnd,XLUT,Y_WF+2*H,"WF3","WF3USED:0");
  add(cb);
  cb=new cCtlCheckBox(hwnd,XLUT,Y_WF+3*H,"WF4","WF4USED:0");
  add(cb);
  //
  // CARRY 
  //
  #define XCARRY 230
  add(new cCtlCheckBox(hwnd,XCARRY,     30,"COUT","COUT_USED:0"));
  pcm=new cCtlMultistate(hwnd,  XCARRY, 60,"No carry");
  pcm->addState("Propagate","CYSELG:1");
  pcm->addState("Generate","CYSELG:G");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XCARRY, 90,"Source...");
  pcm->addState("BY","CY0G:BY");
  pcm->addState("G1","CY0G:G1");
  pcm->addState("G2","CY0G:G2");
  pcm->addState("G1 & G2","CY0G:PROD");
  pcm->addState("1","CY0G:1");
  pcm->addState("0","CY0G:0");
  add(pcm);
  //and the lower slice
  pcm=new cCtlMultistate(hwnd,  XCARRY, 300,"No carry");
  pcm->addState("Propagate","CYSELF:1");
  pcm->addState("Generate","CYSELF:F");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XCARRY, 330,"Source...");
  pcm->addState("BY","CY0F:BY");
  pcm->addState("F1","CY0F:G1");
  pcm->addState("F2","CY0F:F2");
  pcm->addState("F1 & F2","CY0F:PROD");
  pcm->addState("1","CY0F:1");
  pcm->addState("0","CY0F:0");
  add(pcm);
  //carry input
  pcm=new cCtlMultistate(hwnd,  XCARRY, 390,"carry in");
  pcm->addState("BX","CYINIT:BX");
  pcm->addState("CIN","CYINIT:CIN");
  add(pcm);
  //
  // MUX
  //
  #define XMUX 325
  pcm=new cCtlMultistate(hwnd,  XMUX, 75,"unused");
  pcm->addState("  FX","GYMUX:FX");
  pcm->addState("GXOR","CYINIT:GXOR");
  pcm->addState("  G","CYINIT:G");
  add(pcm);
    //
  pcm=new cCtlMultistate(hwnd,  XMUX, 290,"unused");
  pcm->addState("  F5","FXMUX:F5");
  pcm->addState("FXOR","FXMUX:FXOR");
  pcm->addState("  F","FXMUX:F");
  add(pcm);
   //
   // FF
   //
   #define XFF 390
  pcm=new cCtlMultistate(hwnd,  XFF-10  , 45,"no input");
  pcm->addState("in:Logic","DYMUX:1");
  pcm->addState("in:BY","DYMUX:0");
  add(pcm);
 //
  pcm=new cCtlMultistate(hwnd,  XFF, 75,"storage");
  pcm->addState("Flip-flop","FFY:#FF");
  pcm->addState("Latch","FFY:#LATCH");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XFF, 105,"init");
  pcm->addState("  0","FFY_INIT_ATTR:0");
  pcm->addState("  1","FFY_INIT_ATTR:1");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XFF, 135,"sr");
  pcm->addState("sr high","FFY_SR_ATTR:SRHIGH");
  pcm->addState("sr low","FFY_SR_ATTR:SRLOW");
  add(pcm);
//
  add(new cCtlCheckBox(hwnd,XFF,    200,"REV","REVUSED:0"));
  add(new cCtlCheckBox(hwnd,XFF,    220,"SR","SRFFMUX:0"));
//
  pcm=new cCtlMultistate(hwnd,  XFF-10  , 270,"no input");
  pcm->addState("in:Logic","DXMUX:1");
  pcm->addState("in:BX","DXMUX:0");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XFF, 300,"storage");
  pcm->addState("Flip-flop","FFX:#FF");
  pcm->addState("Latch","FFX:#LATCH");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XFF, 330,"init");
  pcm->addState("  0","FFX_INIT_ATTR:0");
  pcm->addState("  1","FFX_INIT_ATTR:1");
  add(pcm);
  pcm=new cCtlMultistate(hwnd,  XFF, 360,"sr");
  pcm->addState("sr high","FFX_SR_ATTR:SRHIGH");
  pcm->addState("sr low","FFX_SR_ATTR:SRLOW");
  add(pcm);
//
// outputs
//
   #define XOUT 530
  pcm=new cCtlMultistate(hwnd,  XOUT, 100,"YB");
  pcm->addState("YB COUT","YBMUX:1");
  pcm->addState("YB MC15","YBMUX:0");
  add(pcm);
  add(new cCtlCheckBox(hwnd, XOUT,    118,"YB used","YBUSED:0"));
//
  add(new cCtlCheckBox(hwnd, XOUT,    140,"BY","BYOUTUSED:0"));
  add(new cCtlCheckBox(hwnd, XOUT,    140+1*H,"BYINV","BYINVOUTUSED:0"));
//  
  add(new cCtlCheckBox(hwnd, XOUT,    140+3*H,"FX","FXUSED:0"));
//  
  add(new cCtlCheckBox(hwnd, XOUT,    140+5*H,"Y","YUSED:0"));
//  
  add(new cCtlCheckBox(hwnd, XOUT,    140+7*H,"DIG","DIGUSED:0"));
//   
  add(new cCtlCheckBox(hwnd, XOUT,    140+9*H,"F5","F5USED:0"));
//   
  add(new cCtlCheckBox(hwnd, XOUT,    140+11*H,"X","XUSED:0"));
//
// Sync
//
  pcm=new cCtlMultistate(hwnd,  XOUT, 400,"unused");
  pcm->addState("SYNC","SYNC_ATTR:SYNC");
  pcm->addState("ASYNC","SYNC_ATTR:ASYNC");
  add(pcm);
  }

CLASS::~CLASS(){
}

void CLASS::Output(FILE*f){
  int i;
  for(i=0;i<index;i++){
    cControl* ctl = controls[i];
    const char* data = ctl->getData();
    if(data){
      fputs(data,f);
      fputs(" ",f);
    }
  }
}





