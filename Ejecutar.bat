SET "flex_path=E:\GnuWin32\bin\flex"
SET "bison_path=E:\GnuWin32\bin\bison"
SET "mingw_gcc_path=E:\MinGW\bin\gcc.exe"
%flex_path% "%~d0%~p0Lexico.l"
pause
%bison_path% -dyv "%~d0%~p0Sintactico.y"
pause
%mingw_gcc_path% lex.yy.c y.tab.c -std=gnu99 -o "%~d0%~p0Primera.exe"
pause
"%~d0%~p0Primera.exe" prueba.txt
pause
