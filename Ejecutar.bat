SET "flex_path=C:\GnuWin32\bin\flex"
SET "bison_path=C:\GnuWin32\bin\bison"
SET "mingw_gcc_path=C:\MinGW\bin\gcc.exe"
%flex_path% "%~d0%~p0Lexico.l"
pause
%bison_path% -dyv "%~d0%~p0Sintactico.y"
pause
%mingw_gcc_path% lex.yy.c y.tab.c "libs/tabla_simbolos/tabla_simbolos.c" "libs/tercetos/tercetos.c" "libs/sentencias_control/sentencias_control.c" "libs/funciones_especiales/funciones_especiales.c" "libs/generacion_assembler/generacion_assembler.c" -std=gnu99 -o "%~d0%~p0Grupo11.exe"
pause
"%~d0%~p0Grupo11.exe" "prueba.txt"
pause