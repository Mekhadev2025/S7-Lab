%option noyywrap

%%

[a-zA-Z][a-zA-Z0-9]*   { printf("valid id present\n"); }
[0-9][a-zA-Z0-9]*      { printf("Nopeee\n"); }

%%

int main() {
    yylex();
    return 0;
}