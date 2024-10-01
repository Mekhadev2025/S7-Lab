 %{
#include <stdio.h>
#include <ctype.h>

int yylex(void);
void yyerror(const char *s);
%}

/* Declare the token */
%token LETTERS_DIGITS

%%
variable : LETTERS_DIGITS { printf("Valid variable: %s\n", yytext); }
        ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter a variable name: ");
    yyparse();
    return 0;
}
