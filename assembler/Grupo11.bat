PATH="%~d0%~p0\TASM"

tasm numbers.asm
tasm Final.asm
tlink Final.obj numbers.obj
Final.exe
del Final.obj 
del numbers.obj 
del Final.exe
del Final.map