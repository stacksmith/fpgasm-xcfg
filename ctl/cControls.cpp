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
 cCellControls presents a multiple set of controls. 
*****************************************************************************/
#include "global.h"
#include "cControl.h"
#include "cCtlCheckBox.h"
#include "cCtlMultistate.h"

#include "cControls.h"
#define CLASS cControls

CLASS::CLASS(HWND hwnd,U32 xmax){
  max=xmax;
  //our controls consist of a bunch of controls...
  controls=(cControl**)malloc(max*sizeof(cControl*));
  memset(controls,0,sizeof(max*sizeof(cControl*)));
  index=0;
}


CLASS::~CLASS(){
}

void CLASS::add(cControl*ctl){
  controls[index++]=ctl;
}
void CLASS::draw(HDC hdc){
  int i=0;
  cControl* pControl;
  for(i=0;i<index;i++){
    pControl=controls[i];
    pControl->draw(hdc);
    }
}

cControl* CLASS::find(U32 x,U32 y){
  int i;
  cControl* pControl;
  for(i=0;i<index;i++){
    pControl=controls[i];
    if(pControl->isIn(x, y))
      return pControl;
  }
  return NULL;
}


