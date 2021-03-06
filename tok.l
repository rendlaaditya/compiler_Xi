%{
#include "calc.tab.h"
#include "calc.h"
#include<stdlib.h>

int Adr=0;
symrec *sym_table = (symrec *)0;
%}
number [0-9]+
id [a-z]+
%%
[ \t\n] {}
"while" {return WHILE;}
"if"	{return IF;}
"main"	{return MAIN;}
"else"	{return ELSE;}
"int"	{return INT;}
"bool"	{return BOOL;}
"=="   {yylval.val=0;return RELOP;}
"!="   {yylval.val=1;return RELOP;}
"<"   {yylval.val=2;return RELOP;}
">"   {yylval.val=3;return RELOP;}
"<="   {yylval.val=4;return RELOP;}
">="   {yylval.val=5;return RELOP;}
{number} {sscanf(yytext,"%d",&yylval.val);return NUM;}
{id} {yylval.str=strdup(yytext);return VAR;}
\n|.  {return yytext[0];}
%%

/* The symbol table: a chain of `struct symrec'.  */


symrec * putsym (char *sym_name,int sym_type,int offset){
  symrec *ptr;
  ptr = (symrec *) malloc (sizeof (symrec));
  ptr->name = (char *) malloc (strlen (sym_name) + 1);
  strcpy (ptr->name,sym_name);
  sprintf(ptr->addr,"%d",Adr); /* set value to 0 even if fctn.  */
  Adr=Adr+offset;
  ptr->next = (struct symrec *)sym_table;
  sym_table = ptr;
  return ptr;
}

symrec *getsym (char *sym_name){
  symrec *ptr;
  for (ptr = sym_table; ptr != (symrec *) 0;
       ptr = (symrec *)ptr->next)
    if (strcmp (ptr->name,sym_name) == 0)
      return ptr;
  return 0;
}
