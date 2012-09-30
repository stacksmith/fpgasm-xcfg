**FPGASM-XCFG  - PRE-ALPHA - EXPECT FREQUENT CHANGES**

Lacking idetic memory, I find myself referring to fpga editor a lot,
which is less than fun.

xcfg is a quick-and-dirty, somewhat-visual tool for quickly configuring
a spartan3 slice.  If it is useful I intend to add IOBs etc.


**USAGE**

invoke xcfg on a command line (using wine on linux).  Fill in the form by
clicking on checkboxes and multistate text-buttons.  Hit enter to exit;
output is printed to stdout.  

I will put the output into the cut-paste buffer ASAP.

**CROSS-PLATFORM NOTES**

Eesh, don't get me started.  I could not think of a better way without using
gigantic libraries, learning curves and installation headaches.  I wound
up using Win32, the *lingua franca* of the computing world (as it is supported
on everything I can think of).

This project is intended to compile under MINGW.  In that environment it will
run as is.

To run under wine xcfg.exe needs the following dlls:
'''
libgcc_s_dw2-1.dll  libstdc++-6.dll
'''
I did not include them as I don't know their legal status.  I think they are 
MINGW libraries.  If you know, elucidate me at fpgasm AT apple2.x10.mx.

For non-mingw windows you will probably need these dlls as well.

I will try to clean up the installation as this project matures.

**CODING NOTES**

My C-- style has annoyed the purists, but at this stage of the game I am just
posting personal code.  I have reasons to avoid most C++ features (another
discussion), and use C++ mostly as an organizational aid.

I also have reasons for creating custom controls the way I did.  They are
segregated in the ctl directory.


