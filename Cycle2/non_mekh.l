%{
#include <stdio.h>
%}

%%

"Mekh"         {/* Ignore the strings containing "Mekh" */}
[^M]+          { printf("/n%s", yytext); }
M([^e]|e([^k]|k([^h])))* { printf("/n%s", yytext); }

%%

int main(void) {
    yylex();
    return 0;
}