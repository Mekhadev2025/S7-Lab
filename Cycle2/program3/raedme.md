
Instructions to Run 
---------------

1.bison -d calc.y<br>
2.flex calc.l<br>
3.gcc -o calculator lex.yy.c calc.tab.c -lfl
4. ./calculator


