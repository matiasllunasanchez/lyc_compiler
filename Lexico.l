%{ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"

#define INTEGER_MAX  32767
#define INTEGER_MIN  -32768
#define REAL_MAX 3.402823e+38
#define REAL_MIN 1.175494e-38
#define STRING_MAX_CHAR 32
#define ID_MAX_CHAR 30

void validacion_string();
void validacion_int();
void validacion_real();
void validacion_id();

FILE  *yyin;
char *yytext;
int yylex();
int yyparse();
 
%}

%option noyywrap
%option yylineno

ESPACIO                 " "
DIGITO		            [0-9]
CERO                    "0"
DIGITO_SIN_CERO		    [1-9]
LETRA			        [a-zA-ZñÑ]

CARACTERES              @|\?|\.|\,|\+|\t|\n|\/|\_|\:|\;|¿|\*|{LETRA}|{DIGITO}|{ESPACIO}|\=|\*|\>\<|\-|á|Á|é|É|í|Í|ó|Ó|ú|Ú|ü|ñ|Ñ|¡|\¿|%
COMA                    ","

PAR_A	                "("
PAR_C	                ")"

COR_A                   "["
COR_C                   "]"
PYC                     ";"

BETWEEN                "BETWEEN"
TAKE                    "TAKE"
WRITE                   "WRITE"
READ                    "READ"
DECVAR		            "DECVAR"
ENDDEC	                "ENDDEC"

IF			            "IF"
THEN			        "THEN"
ENDIF                   "ENDIF"
INTEGER	            	"INTEGER"
STRING                  "STRING"
FLOAT		            "FLOAT"
ELSE		            "ELSE"
AND                     "AND"
OR                      "OR"
NOT                     "NOT"
WHILE	            	"WHILE"
ENDWHILE                "ENDWHILE"

CONST_ENT	            {CERO}|("-"?({DIGITO_SIN_CERO}({DIGITO}*)))
CONST_REAL              {CONST_ENT}+"."{DIGITO}*|{CONST_ENT}*"."{DIGITO}+
CONST_STR               \"{CARACTERES}*\"
COMENTARIO	            \-\/.*\/\-

ID		            	{LETRA}({LETRA}|{DIGITO})*

OP_MAYOR		        ">"
OP_MAYOR_IGUAL	            ">="
OP_MENOR		        "<"
OP_MENOR_IGUAL	            "<="
OP_IGUAL	            "=="
OP_NO_IGUAL		        "!="
OP_TIPO                 ":"

OP_ASIG		            ":="
OP_DIV                  "/"
OP_SUM                 "+"
OP_MUL		            "*"
OP_RES                "-"

%%

{DECVAR}         { printf("\n DECVAR: %s\n",yytext);return DECVAR; }
{ENDDEC}         { printf("\n ENDDEC: %s\n",yytext);return ENDDEC; }
{TAKE}           { printf("\n TAKE: %s\n",yytext);return TAKE; }
{BETWEEN}        { printf("\n BETWEEN: %s\n",yytext);return BETWEEN; }
{WRITE}          { printf("\n WRITE: %s\n",yytext);return WRITE; }
{READ}           { printf("\n READ: %s\n",yytext);return READ; }
{WHILE}          { printf("\n nWHILE: %s\n",yytext);return WHILE; }
{IF}             { printf("\n IF: %s\n",yytext);return IF; }
{THEN}           { printf("\n THEN: %s\n",yytext);return THEN; }
{INTEGER}        { printf("\n INTEGER: %s\n",yytext);return INTEGER; }
{FLOAT}          { printf("\n FLOAT: %s\n",yytext);return FLOAT; }
{ELSE}           { printf("\n ELSE: %s\n",yytext);return ELSE; }
{ENDWHILE}       { printf("\n ENDWHILE: %s\n",yytext);return ENDWHILE; }
{STRING}         { printf("\n STRING: %s\n",yytext);return STRING; }   
{ENDIF}          { printf("\n ENDIF: %s\n",yytext);return ENDIF; } 

{AND}            { printf("\n AND: %s\n",yytext);return AND; }
{OR}             { printf("\n OR: %s\n",yytext);return OR; }
{NOT}            { printf("\n NOT: %s\n",yytext);return NOT; }

{CONST_ENT}      { printf("\n Constante Entera: %s\n", yytext);
                   validacion_int();
                   return CONST_ENT; }
{CONST_STR}      { printf("\n Constante String: %s\n", yytext);
                   validacion_string();
                   return CONST_STR; }
{CONST_REAL}     { printf("\n Constante Real: %s\n", yytext);
                   validacion_real();
                   return CONST_REAL; }

{ID}             { printf("\n ID Variable: %s\n", yytext);
                   validacion_id();
                   return ID; }
{COMA}           { printf("\n Coma: %s\n",yytext);return COMA; }

{PAR_A}	         { printf("\n Parentesis Abre: %s\n",yytext);return PAR_A; }
{PAR_C}	         { printf("\n Parentesis Cierra: %s\n",yytext);return PAR_C; }

{COR_A}          { printf("\n Corchete Abre: %s\n",yytext);return COR_A; }
{COR_C}          { printf("\n Corchete Cierra: %s\n",yytext);return COR_C; }

{PYC}	         { printf("\n Punto y Coma: %s\n",yytext);return PYC; }

{OP_ASIG}	     { printf("\n Operador Asignacion: %s\n",yytext);return OP_ASIG; }
{OP_MAYOR}		 { printf("\n Operador Mayor: %s\n",yytext);return OP_MAYOR; }
{OP_MAYOR_IGUAL} { printf("\n Operador Mayor o igual: %s\n",yytext);return OP_MAYOR_IGUAL; }
{OP_MENOR}       { printf("\n Operador Menor: %s\n",yytext);return OP_MENOR; }
{OP_MENOR_IGUAL} { printf("\n Operador Menor o Igual: %s\n",yytext);return OP_MENOR_IGUAL; }
{OP_IGUAL}       { printf("\n Operador Igual: %s\n",yytext);return OP_IGUAL; }
{OP_TIPO}        { printf("\n Operador de tipo: %s\n",yytext);return OP_TIPO; }
{OP_NO_IGUAL}    { printf("\n Operador Distinto : %s\n",yytext);return OP_NO_IGUAL; }
{OP_DIV}         { printf("\n Operador Divison: %s\n",yytext);return OP_DIV; }
{OP_SUM}         { printf("\n Operador Suma: %s\n",yytext);return OP_SUM; }
{OP_MUL}         { printf("\n Operador Multiplicacion: %s\n",yytext);return OP_MUL; } 
{OP_RES}         { printf("\n Operador Resta: %s\n",yytext);return OP_RES; }

{COMENTARIO}

"\n"  
"\t"
"\r" 
"\n\t" 
"\r\n"               
" "                 
.                { printf("Error lexico: Caracter invalido: %s", yytext); exit(1);}

%%


int main(int argc,char *argv[])
{
    if ((yyin = fopen(argv[1], "rt")) == NULL)
        {
            printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
        }
    else
        {
            yyparse();
        }
        fclose(yyin);
        return 1;
}

void validacion_string()
{
    if (yyleng > STRING_MAX_CHAR)
    {
        printf("Capacidad maxima de caracteres asignados superada en la linea %d\n", yylineno);
        exit(1);
    }
    char *str_cte = (char *) malloc(sizeof(char[yyleng]));
    strcpy(str_cte, "_");
    char *result = yytext+1;
    result[strlen(result)-1] = '\0';
    strcat(str_cte, result);
    strcpy(yylval.str_val, str_cte);
}

void validacion_int()
{
    if (atoll(yytext) < INTEGER_MIN  || atoll(yytext) > INTEGER_MAX )
    {
        printf("Constante entera fuera de rango en la linea %d\n", yylineno);
        exit(1);
    }
    yylval.int_val = atoi(yytext);
}

void validacion_real()
{
    if (atof(yytext) < REAL_MIN || atof(yytext) > REAL_MAX)
    {
        printf("Constante real fuera de rango en la linea %d\n", yylineno);
        exit(1);
    }
    yylval.real_val = atof(yytext);
}

void validacion_id()
{
    if (yyleng > ID_MAX_CHAR)
    {
        printf("Capacidad maxima de caracteres asignados al ID superada en la linea %d\n", yylineno);
        exit(1);
    }
    yylval.str_val = strdup(yytext);
}

int yyerror(char* mensaje)
 {
    printf("Syntax Error (linea %d): %s\n", yylineno, mensaje);
    system ("Pause");
    exit (1);
 }