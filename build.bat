REM windres gdi01.rc resfile.o
g++ -c main.cpp  cCanvas.cpp cBitmap.cpp cSliceM.cpp -D_WIN32_WINNT=0x0501
g++   -mconsole -mwindows -o xcfg.exe  main.o  cCanvas.o  cBitmap.o  cSliceM.o ctl\cControl.o ctl\cCtlCheckBox.o ctl\cCtlMultistate.o ctl\cControls.o ctl\stb_image.o
REM -l user32 -lkernel32 -ladvapi32 -lshell32  -lgdi32 

