bison calc.y -d
flex tok.l
gcc calc.tab.c lex.yy.c -lfl
