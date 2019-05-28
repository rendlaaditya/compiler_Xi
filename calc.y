%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>  
#include "calc.h"  /* Contains definition of `symrec'        */
int  yylex(void);
void yyerror (char  *);
int b=0,n=1;
int r=7;
int labels=0;
int count=0;
int labelcount=0;
FILE *fp;
struct StmtsNode *final;
struct node *afinal;
void StmtsTrav(stmtsptr ptr);
void StmtTrav(stmtptr ptr);
void mipscodeprinter(struct node* root,int b);
int max(int a,int b);
int min(int a,int b);
void doer(struct node* ptr);
void makeershov(struct node* root);
%}
%union {
int   val;  /* For returning numbers.                   */
char *str;/*for returning strings*/
struct symrec  *tptr;   /* For returning symbol-table pointers      */
char c[1000];
char nData[100];
struct node *e;
struct StmtNode *stmtptr;
struct StmtsNode *stmtsptr;
}


/* The above will cause a #line directive to come in calc.tab.h.  The #line directive is typically used by program generators to cause error messages to refer to the original source file instead of to the generated program. */

%token  <val> NUM        /* Integer   */
%token <val> RELOP
%token  WHILE
%token MAIN
%token IF
%token ELSE
%token INT
%token BOOL
%type <val> digits
%token <str> VAR   
%type  <e>  exp
%type <e> x
%type <stmtsptr> stmts
%type <stmtptr> stmt
%type <stmtsptr> elsestmt
%type <stmtptr> bexp
%right '='
%left '-' '+'
%left '*' '/'


/* Grammar follows */

%%
prog: stmts {final=$1;};
stmts: stmt {$$=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
   $$->singl=1;$$->left=$1,$$->right=NULL;}
| stmt stmts {$$=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
   $$->singl=0;$$->left=$1,$$->right=$2;}
;

stmt:
          '\n' {$$=NULL;}
	| MAIN '(' ')' '{' stmts '}'  {$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));$$->ismain=1;
		$$->downstmts=$5;
		}
	| VAR ':' INT ';'  {printf("1\n");symrec *s;s=getsym($1);if (s==0) s=putsym($1,VAR,4);$$=NULL;printf("2\n");}
	| VAR ':' BOOL ';'  {symrec *s;s=getsym($1);if (s==0) s=putsym($1,VAR,4);$$=NULL;}
	| VAR ':' INT'['digits']' ';' {symrec *s=getsym($1);if (s==0) s=putsym($1,VAR,4*$5);$$=NULL;}
	| IF '(' bexp ')' '{'  stmts '}'  elsestmt {$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
				if ($8!=NULL){
						$$->isif=0;$$->isWhile=0;$$->iselse=1;}
				else{$$->isif=1;$$->isWhile=0;$$->iselse=0;}
						sprintf($$->initCode,"%s", $3->initCode);
					    int rr=$3->relop;
					    if (rr==0){sprintf($$->initJumpCode,"bne $t0, $t1, ");}
					    else if (rr==1){sprintf($$->initJumpCode,"beq $t0, $t1, ");}
					    else if (rr==2){sprintf($$->initJumpCode,"bge $t0, $t1, ");}
					    else if (rr==3){sprintf($$->initJumpCode,"ble $t0, $t1, ");}
					    else if (rr==4){sprintf($$->initJumpCode,"bgt $t0, $t1, ");}
					    else if (rr==5){sprintf($$->initJumpCode,"blt $t0, $t1, ");}
					    $$->downstmts=$6;$$->downelse=$8;			
				}
        | WHILE '(' bexp ')' '{'  stmts '}' {printf("while1\n");$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
	    $$->isWhile=1;$$->isif=0;$$->iselse=0;
	    sprintf($$->initCode,"%s", $3->initCode);
	    int rr=$3->relop;
	    if (rr==0){sprintf($$->initJumpCode,"bne $t0, $t1, ");}
	    else if (rr==1){sprintf($$->initJumpCode,"beq $t0, $t1, ");}
	    else if (rr==2){sprintf($$->initJumpCode,"bge $t0, $t1, ");}
	    else if (rr==3){sprintf($$->initJumpCode,"ble $t0, $t1, ");}
	    else if (rr==4){sprintf($$->initJumpCode,"bgt $t0, $t1, ");}
	    else if (rr==5){sprintf($$->initJumpCode,"blt $t0, $t1, ");}
	    $$->downstmts=$6;
	  }  
        | VAR '=' exp ';'    {$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
	    $$->isWhile=0;$$->isif=0;$$->iselse=0;symrec *s=getsym($1);
	    /*sprintf($$->bodyCode,"%s\nsw $t0,%s($t8)\n", $3, $1->addr);*/
	    sprintf($$->tostore,"%d",atoi(s->addr));
	    $$->down=$3;
	    /*printf("%s\n",$1->addr);*/}
	| VAR '[' digits ']' '=' exp ';'  {printf("entered arr assgn\n");$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
	    $$->isWhile=0;$$->isif=0;$$->iselse=0;symrec *s=getsym($1);$$->isarray=2;
	    sprintf($$->tostore,"%d",atoi(s->addr)+4*$3);
	    $$->down=$6;printf("exit arr assgn\n");
	}
	| VAR '[' VAR ']' '=' exp ';'  {$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));
	    $$->isWhile=0;$$->isif=0;$$->iselse=0;symrec *s=getsym($1);symrec *s1=getsym($3);
		$$->isarray=1;
	    sprintf($$->tostore,"%s",s->addr);
	    sprintf($$->index,"%s",s1->addr);
	    $$->down=$6;
	}
        | error  { yyerrok; }
;
/* Invariant: we store the result of an expression in R0 */

exp:      x              { $$=(struct node *) malloc(sizeof(struct node));
			$$=$1;}
	| exp '+' exp	 {$$=(struct node *) malloc(sizeof(struct node));
			$$->left=$1;$$->right=$3;$$->leafbool=0;$$->op='+';
				}
				
	| exp '-' exp	 {$$=(struct node *) malloc(sizeof(struct node));
				$$->left=$1;$$->right=$3;$$->leafbool=0;$$->op='-';
			}
	| exp '*' exp	 {$$=(struct node *) malloc(sizeof(struct node));
				 $$->left=$1;$$->right=$3;$$->leafbool=0;$$->op='*';
			}
	| exp '/' exp	 {$$=(struct node *) malloc(sizeof(struct node));
				$$->left=$1;$$->right=$3;$$->leafbool=0;$$->op='/';
			}
	| '(' exp ')'	 {$$=(struct node *) malloc(sizeof(struct node));
				 $$=$2;
			}
;
bexp:    VAR RELOP VAR {$$=(struct StmtNode *) malloc(sizeof(struct StmtNode)); symrec *s=getsym($1);symrec *s2=getsym($3);
		        sprintf($$->initCode,"lw $t0, %s($t%d)\nlw $t1, %s($t%d)\n",s->addr,r+1,s2->addr,r+1);$$->relop=$2;}
	|digits RELOP VAR {$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));symrec *s=getsym($3);
                        sprintf($$->initCode,"li $t0, %d\nlw $t1, %s($t%d)\n", $1,s->addr,r+1);$$->relop=$2;}
	|VAR RELOP digits {printf("enterred relop bexp\n");$$=(struct StmtNode *) malloc(sizeof(struct StmtNode));symrec *s=getsym($1);
		        sprintf($$->initCode,"lw $t0, %s($t%d)\nli $t1, %d\n", s->addr,r+1,$3);$$->relop=$2;printf("exit relop bexp\n");}
;
elsestmt: {$$=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
				$$=NULL;}
	|ELSE '{' stmts '}'  {$$=(struct StmtsNode *) malloc(sizeof(struct StmtsNode));
				$$=$3;
				}
;
x:   digits {$$=(struct node *) malloc(sizeof(struct node));
		$$->left=NULL;$$->right=NULL;$$->leafbool=1;$$->isnum=1;
		sprintf($$->address,"%d",$1);}	
	| VAR {$$=(struct node *) malloc(sizeof(struct node));
		$$->left=NULL;$$->right=NULL;$$->leafbool=1;$$->isnum=0;symrec *s=getsym($1);
		sprintf($$->address,"%s",s->addr);/*printf("%s this is number value",$$->address);*/}
	| VAR '['digits']'  {$$=(struct node *) malloc(sizeof(struct node));symrec *s=getsym($1);
			$$->left=NULL;$$->right=NULL;$$->leafbool=1;$$->isnum=0;$$->isarray=1;$$->arrind=$3;
					sprintf($$->address,"%s",s->addr);
			}
	| VAR '['VAR']' {$$=(struct node *) malloc(sizeof(struct node));$$->isarray=2;symrec *a=getsym($1);symrec *b=getsym($3);
			$$->left=NULL;$$->right=NULL;$$->leafbool=1;$$->isnum=0;
		sprintf($$->aind,"%s",b->addr);sprintf($$->address,"%s",a->addr);
		}
   ;
digits: '-' NUM {$$=-$2;}
	|NUM {$$=$1;}
;
/* End of grammar */
%%

void StmtsTrav(stmtsptr ptr){
	  //printf("%d\n",ptr->singl);
	  if(ptr->singl==1)StmtTrav(ptr->left);
	  else{
	  	StmtTrav(ptr->left);
	  	StmtsTrav(ptr->right);
	  }
}
void doer(e ptr){
	makeershov(ptr);
	//printf("ershov %d",ptr->ershov);
	mipscodeprinter(ptr,1);
}
void StmtTrav(stmtptr ptr){
	if (ptr!=NULL){
		//printf("iswhile %d\n",ptr->isWhile);
	  	if(ptr->isif==1){
			fprintf(fp,"Lbl%d:\n",labelcount);
			fprintf(fp,"%s",ptr->initCode);
			fprintf(fp,"%s",ptr->initJumpCode);
			fprintf(fp,"Lbl%d\n",labelcount+1);
			StmtsTrav(ptr->downstmts);
			fprintf(fp,"j Lbl%d\n",labelcount+1);
			labelcount=labelcount+2;
		}
		else if (ptr->iselse==1){
			fprintf(fp,"Lbl%d:\n",labelcount);
			fprintf(fp,"%s",ptr->initCode);
			fprintf(fp,"%s",ptr->initJumpCode);
			fprintf(fp,"Lbl%d\n",labelcount+1);
			StmtsTrav(ptr->downstmts);
			fprintf(fp,"j Lbl%d\n",labelcount+2);
			fprintf(fp,"Lbl%d:\n",labelcount+1);
			StmtsTrav(ptr->downelse);
			fprintf(fp,"Lbl%d:\n",labelcount+2);
			labelcount=labelcount+2;
		}
	  	else if (ptr->isWhile==1){	
			fprintf(fp,"\nLbl%d:\n",labelcount);
			fprintf(fp,"%s",ptr->initCode);
			fprintf(fp,"%s",ptr->initJumpCode);
			fprintf(fp,"Lbl%d\n",labelcount+1);
			StmtsTrav(ptr->downstmts);
			fprintf(fp,"j Lbl%d\n",labelcount);
			fprintf(fp,"\nLbl%d:\n",labelcount+1);
			labelcount=labelcount+1;		
		}
		else if (ptr->isarray==1){
			int offs=atoi(ptr->tostore);
			doer(ptr->down);
			fprintf(fp,"li $t%d, %s($t%d) \n",ptr->down->ershov-1,ptr->index,r+1);
			fprintf(fp,"muli $t%d, $t%d, 4 \n",ptr->down->ershov-1,ptr->down->ershov-1);
			fprintf(fp,"addi $t%d, $t%d, %s\n",ptr->down->ershov-1,ptr->down->ershov-1,ptr->tostore);
			fprintf(fp,"add  $t%d, $t%d, $t%d\n",ptr->down->ershov-1,ptr->down->ershov-1,r+1);
			fprintf(fp,"sw $t%d, 0($t%d)\n",ptr->down->ershov,ptr->down->ershov-1);
		}
		else if (ptr->ismain==1){
			fprintf(fp,"\n main:\n");
			StmtsTrav(ptr->downstmts);
		}
		else{
		fprintf(fp,"%s",ptr->bodyCode);doer(ptr->down);fprintf(fp,"sw t%d %s($t%d)\n",ptr->down->ershov,
			ptr->tostore,r+1);
		}
	}
	else{
		//makeershov(ptr);
		//mipscodeprinter(ptr,1);	
	}
}
void makeershov(struct node*root){
	if (root==NULL)	root->ershov=0;
	else if(root->leafbool==1) {root->ershov=1;}
	else {
		makeershov(root->left);
		makeershov(root->right);
		int b=root->left->ershov;
		int c=root->right->ershov;
		if (b==c){
			root->ershov=b+1;
		}
		else if(b>c) root->ershov=b;
		else root->ershov=c;
	}
	//printf("printing ershov %d\n",root->ershov);
}
int max(int a,int b){
	if (a>=b) return a;
	return b;
}
int min(int a,int b){
	if (a>b) return b;
	return a;
}
void mipscodeprinter(struct node* root,int b){
	int genr;
	if (root->leafbool==1){
		if (root->isnum==1){
			//printf("root->address=%s\n",root->address);
			fprintf(fp,"li $t%d %s\n",b,root->address);
		}
		else if(root->isarray==1){ fprintf(fp,"lw $t%d %d($t%d)\n",b,atoi(root->address)+4*root->arrind,r+1);
		}
		else if(root->isarray=2){ fprintf(fp,"lw $t%d, %s($t%d)\n",b,root->aind,r+1);
				fprintf(fp,"muli $t%d, $t%d ,4\n",b,b);
				fprintf(fp,"add  $t%d, $t%d, %s\n",b,b,root->address);
				fprintf(fp,"add  $t%d, $t%d, $t%d\n",b,b,r+1);
				fprintf(fp,"lw   $t%d, 0($t%d)\n",b,b);
		}
		else{
			fprintf(fp,"lw $t%d %s($t%d)\n",b,root->address,r+1);
		}
	}
	else {
		int kr=root->right->ershov;
		int kl=root->left->ershov;
		if (max(kr,kl)<=r){
			if (kr==kl){
				mipscodeprinter(root->right,b+1);
				mipscodeprinter(root->left,b);
				if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",b+kl,b+kl-1,b+kr);
				else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",b+kl,b+kl-1,b+kr);
				else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",b+kl,b+kl-1,b+kr);
				else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",b+kl,b+kl-1,b+kr);
			}
			else{
				if (kr>kl) genr=1;
				else genr=0;
				if (genr==1){
					mipscodeprinter(root->right,b);
					mipscodeprinter(root->left,b);
					if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",b+kr-1,b+kl-1,b+kr-1);
					else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",b+kr-1,b+kl-1,b+kr-1);
					else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",b+kr-1,b+kl-1,b+kr-1);
					else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",b+kr-1,b+kl-1,b+kr-1);
				}
				else {
					mipscodeprinter(root->right,b);
					mipscodeprinter(root->left,b);
					if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",b+kl-1,b+kr-1,b+kl-1);
					else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",b+kl-1,b+kl-1,b+kr-1);
					else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",b+kl-1,b+kl-1,b+kr-1);
					else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",b+kl-1,b+kl-1,b+kr-1);
				}
			}
		}
		else{
				if (kr>kl) genr=1;
				else genr=0;
				if (genr==1){
					mipscodeprinter(root->right,1);
					fprintf(fp,"sw $r0, $t%d\n",r);
					if (kl>r){mipscodeprinter(root->left,1);}
					else{mipscodeprinter(root->left,r-root->left->ershov+1);}
					fprintf(fp,"lw $t%d $r0",r-1);
					if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",r,r,r-1);
					else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",r,r,r-1);
					else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",r,r,r-1);
					else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",r,r,r-1);
				}
				else{
					mipscodeprinter(root->left,1);
					fprintf(fp,"sw $r0, $t%d\n",r);
					if (kr>r){mipscodeprinter(root->right,1);}
					else{mipscodeprinter(root->right,r-root->right->ershov+1);}
					fprintf(fp,"lw $t%d $r0",r-1);
					if (root->op=='+') fprintf(fp,"add $t%d, $t%d, $t%d\n",r,r-1,r);
					else if (root->op=='-') fprintf(fp,"sub $t%d, $t%d, $t%d\n",r,r-1,r);
					else if (root->op=='*') fprintf(fp,"mul $t%d, $t%d, $t%d\n",r,r-1,r);
					else if (root->op=='/') fprintf(fp,"div $t%d, $t%d, $t%d\n",r,r-1,r);
				}
		}
	}
}

int main ()
{
   fp=fopen("asmb.asm","w");
   fprintf(fp,".data\n\n.text\nli $t%d,268500992\n",r+1);
   yyparse ();
	//makerershov();
   StmtsTrav(final);
   fprintf(fp,"\nli $v0,1\nmove $a0,$t0\nsyscall\n");
   fclose(fp);
}

void yyerror (char *s)  /* Called by yyparse on error */
{
  printf ("%s\n", s);
}


