 %{
#include <stdio.h>
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*    return LETTERS_DIGITS;
.                       { return 0; }

%%
int yywrap() {
    return 1;
}
