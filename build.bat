REM windres gdi01.rc resfile.o
g++ -c main.cpp  cCanvas.cpp cBitmap.cpp cSliceM.cpp -D_WIN32_WINNT=0x0501
g++   -mconsole -mwindows -o xcfg.exe  main.o  cCanvas.o  cBitmap.o  cSliceM.o ctl\cControl.o ctl\cCtlCheckBox.o ctl\cCtlMultistate.o ctl\cControls.o ctl\stb_image.o
REM -l user32 -lkernel32 -ladvapi32 -lshell32  -lgdi32 
REM /******************************************************************************
REM  Copyright 2012 Victor Yurkovsky
REM 
REM     This file is part of FPGAsm
REM 
REM     FPGAsm is free software: you can redistribute it and/or modify
REM     it under the terms of the GNU General Public License as published by
REM     the Free Software Foundation, either version 3 of the License, or
REM     (at your option) any later version.
REM 
REM     FPGAsm is distributed in the hope that it will be useful,
REM     but WITHOUT ANY WARRANTY; without even the implied warranty of
REM     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM     GNU General Public License for more details.
REM 
REM     You should have received a copy of the GNU General Public License
REM     along with FPGAsm.  If not, see <http://www.gnu.org/licenses/>.
REM ******************************************************************************/
