include macros2.asm
include number.asm

.MODEL LARGE
.386
.STACK 200h

.DATA
NEW_LINE DB 0AH,0DH,'$'
CWanterior DW ?
_a dd ?
_b dd ?
_c dd ?
_e dd ?
_f dd ?
_p1 dd ?
_p2 dd ?
_p3 dd ?
_ab dd ?
_d dd ?
_99999_992188 dd 99999.992188
_99_000000 dd 99.000000
_0_999900 dd 0.999900
_cadena_1 db "@sdADaSjfla%dfg", '$'
_cadena_2 db "asldk fh sjf", '$'
_cadena_3 db "ewr", '$'
_30 dd 30
_cadena_4 db "correcto", '$'
_2 dd 2
_cadena_5 db "correcto", '$'
_3 dd 3
_cadena_6 db "correcto NOT", '$'
_1 dd 1
_4 dd 4
@between dd ?
_0 dd 0
_cadena_7 db "ok between", '$'
_2_300000 dd 2.300000
_11_220000 dd 11.220000
_cadena_8 db "ok between 2", '$'
_576 dd 576
_14 dd 14
_neg_34 dd -34

.CODE
START:
mov AX,@DATA
mov DS,AX
mov es,ax

FLD _99999_992188
FSTP _a
FLD _99_000000
FSTP _a
FLD _0_999900
FSTP _a
LEA EAX, _cadena_1
MOV _b, EAX
LEA EAX, _cadena_2
MOV _c, EAX
displayString _cadena_3
displayString NEW_LINE

MOV EBX, _c
displayString [EBX]
displayString NEW_LINE

FLD _a
FILD _30
FXCH
FCOMP
FSTSW AX
SAHF
JA endif527
then524:
LEA EAX, _cadena_4
MOV _e, EAX
endif527:
FLD _a
FILD _2
FXCH
FCOMP
FSTSW AX
SAHF
JAE then539
FLD _a
FILD _2
FXCH
FCOMP
FSTSW AX
SAHF
JB endif542
then539:
LEA EAX, _cadena_5
MOV _f, EAX
endif542:
FLD _a
FILD _3
FXCH
FCOMP
FSTSW AX
SAHF
JA endif552
then549:
LEA EAX, _cadena_6
MOV _f, EAX
endif552:
while554:
FILD _ab
FILD _2
FXCH
FCOMP
FSTSW AX
SAHF
JAE endwhile565
then559:
FILD _ab
FILD _1
FADD
FSTCW CWanterior
OR CWanterior, 0400h
FLDCW CWanterior 
FISTP _ab
JMP while554
endwhile565:
FLD _a
FILD _2
FXCH
FCOMP
FSTSW AX
SAHF
JB between_false581
FILD _4
FADD
FILD _4
FXCH
FMUL
FLD _a
FXCH
FXCH
FCOMP
FSTSW AX
SAHF
JA between_false581
FILD _1
FISTP @between
JMP between_cmp583
BETWEEN_FALSE581:
FILD _0
FISTP @between
BETWEEN_CMP583:
FILD @between
FILD _1
FXCH
FCOMP
FSTSW AX
SAHF
then585:
LEA EAX, _cadena_7
MOV _f, EAX
endif588:
FLD _a
FLD _2_300000
FXCH
FCOMP
FSTSW AX
SAHF
JB between_false600
FLD _a
FLD _11_220000
FXCH
FCOMP
FSTSW AX
SAHF
JA between_false600
FILD _1
FISTP @between
JMP between_cmp602
BETWEEN_FALSE600:
FILD _0
FISTP @between
BETWEEN_CMP602:
FILD @between
FILD _1
FXCH
FCOMP
FSTSW AX
SAHF
then604:
LEA EAX, _cadena_8
MOV _f, EAX
endif607:
FILD _576
FISTP _d
FILD _14
FISTP _d
FILD _neg_34
FISTP _d
FILD _0
FISTP _d
FILD _0
FISTP _d

mov ax,4c00h
Int 21h
End START
