SET "flex_path=E:\GnuWin32\bin\flex"
SET "bison_path=E:\GnuWin32\bin\bison"
SET "mingw_gcc_path=E:\MinGW\bin\gcc.exe"
%flex_path% "%~d0%~p0Lexico.l"
pause
%bison_path% -dyv "%~d0%~p0Sintactico.y"
pause
%mingw_gcc_path% lex.yy.c y.tab.c "libs/tabla_simbolos/tabla_simbolos.c" "libs/tercetos/tercetos.c" -std=gnu99 -o "%~d0%~p0Segunda.exe"
pause
"%~d0%~p0Segunda.exe" "prueba.txt"
pause
@REM "%~d0%~p0Segunda.exe" "tests/tercetos/prueba_peque.txt"
@REM pause