// "Copyright 2022 <Copyright Plastiqu>"

#include <stdlib.h>

#include "./polska_math.h"

#define sin 'S'
#define cos 'C'
#define tan 'T'
#define ctg 'G'
#define sqrt 'Q'
#define ln 'L'

struct Stack {
  char c;
  struct Stack *Next;
};

int Prior(char);
struct Stack* InString(struct Stack*, char);
struct Stack* OutString(struct Stack*, char*);

double polska_parcer(char formula[100], double x) {
  struct Stack *t, *Op = NULL;
  char a, Out[100];
  int k = 0, l = 0;
  while (formula[k] != '\0') {
    if (formula[k] == ')') {
      while ((Op -> c) != '(') {
        Op = OutString(Op, &a);
        if (!Op) {
          a = '\0';
        }
        Out[l++] = a;
        Out[l++] = ' ';
      }
      t = Op;
      Op = Op -> Next;
      free(t);
    }
    if ((formula[k] == 's' && formula[k+1] == 'i'
       && formula[k+2] == 'n' && formula[k+3] == '(')) {
      Op = InString(Op, sin);
      Out[l++] = ' ';
    }
    if ((formula[k] == 'c' && formula[k+1] == 'o'
       && formula[k+2] == 's' && formula[k+3] == '(')) {
      Op = InString(Op, cos);
      Out[l++] = ' ';
    }
    if ((formula[k] == 't' && formula[k+1] == 'a'
       && formula[k+2] == 'n' && formula[k+3] == '(')) {
      Op = InString(Op, tan);
      Out[l++] = ' ';
    }
    if ((formula[k] == 'c' && formula[k+1] == 't'
      && formula[k+2] == 'g' && formula[k+3] == '(')) {
      Op = InString(Op, ctg);
      Out[l++] = ' ';
    }
    if ((formula[k] == 's' && formula[k+1] == 'q'
      && formula[k+2] == 'r' && formula[k+3] == 't' && formula[k+4] == '(')) {
      Op = InString(Op, sqrt);
      Out[l++] = ' ';
    }
    if ((formula[k] == 'l' && formula[k+1] == 'n' && formula[k+2] == '(')) {
      Op = InString(Op, ln);
      Out[l++] = ' ';
    }
    if (formula[k] == 'x') {
      Out[l++] = formula[k];
      Out[l++] = ' ';
    }
    if ((formula[k] >= '0' && formula[k] <= '9')
      && (formula[k+1] >= '0' && formula[k+1] <= '9')) {
      Out[l++] = formula[k];
    } else if (formula[k] >= '0' && formula[k] <= '9') {
      Out[l++] = formula[k];
      Out[l++] = ' ';
    }
    if ( formula[k] == '(' )
      Op = InString(Op, formula[k]);
    if ( formula[k] == '+' || formula[k] == '-' || formula[k] == '*'
      || formula[k] == '/' || formula[k] == 'S' || formula[k] == 'C'
      || formula[k] == 'T' || formula[k] == 'G' || formula[k] == 'L'
      || formula[k] == 'Q') {
      while (Op != NULL && Prior(Op -> c) >= Prior(formula[k])) {
        Op = OutString(Op, &a);
        Out[l++] = a;
        Out[l++] = ' ';
      }
      Op = InString(Op, formula[k]);
    }
    k++;
  }
  while (Op !=NULL) {
    Op = OutString(Op, &a);
    Out[l++] = a;
  }
  Out[l] = '\0';
  return polska_math(Out, x);
}
int Prior(char a) {
  switch (a) {
    case 'Q': return 5;
    case 'S': case 'C': case 'T': case 'G': case 'L': return 4;
    case '*': case '/': return 3;
    case '-': case '+': return 2;
    case '(': return 1;
  }
  return 0;
}
struct Stack* InString(struct Stack *t, char s) {
  struct Stack *t1 = (struct Stack*)malloc(sizeof(struct Stack));
  t1 -> c = s;
  t1-> Next = t;
  return t1;
}
struct Stack* OutString(struct Stack *t, char *s) {
  struct Stack *t1 = t;
  *s = t -> c;
  t = t->Next;
  free(t1);
  return t;
}
