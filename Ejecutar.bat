SET "flex_path=C:\GnuWin32\bin\flex"
SET "bison_path=C:\GnuWin32\bin\bison"
SET "mingw_gcc_path=C:\MinGW\bin\gcc.exe"
%flex_path% %~d0%~p0Lexico.l
pause
%bison_path% -dyv %~d0%~p0Sintactico.y
pause
%mingw_gcc_path% lex.yy.c y.tab.c -o %~d0%~p0Primera.exe
pause
pause
%~d0%~p0Primera.exe prueba.txt
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
pause
