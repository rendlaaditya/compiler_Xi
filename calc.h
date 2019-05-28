/* Data type for links in the chain of symbols.      */
struct symrec
{
  char *name;  /* name of symbol                     */
  char addr[100];           /* value of a VAR          */
  char *str[100];
  struct symrec *next;    /* link field              */
};

typedef struct symrec symrec;



/* The symbol table: a chain of `struct symrec'.     */
extern symrec *sym_table;

symrec *putsym ();
symrec *getsym ();

typedef struct StmtsNode *stmtsptr;
typedef struct StmtNode *stmtptr;
typedef struct node *e;

 struct StmtsNode{
   int singl;
   struct StmtNode *left;
   struct StmtsNode *right;
 };



struct StmtNode{
   int isWhile;
	int isif;
	int ismain;
	int iselse;
	int isarray;
   char initCode[100];
   char initJumpCode[20];
   char bodyCode[1000];
   int label;
	char index[1000];
	char tostore[1000];
	int relop;            
  struct node *down;
   struct StmtsNode *downstmts;
   struct StmtsNode *downelse;
};

struct node{
	//char ndata[1000];
	char op;
	int leafbool;
	int isnum;
	int isarray;
	int arrind;
	char aind[1000];
	int ershov;
	char arrcode[1000];
	char address[1000];
	struct node* left;
	struct node* right;
};



/*void StmtsTrav(stmtsptr ptr);
  void StmtTrav(stmtptr *ptr);*/
