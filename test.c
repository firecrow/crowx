#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
int exit_called = 0;
#include "crowx.c"

#define exit(XARG) \
  do { \
      fprintf(stderr, "exit called for %d\n", XARG); \
      exit_called = 1; \
  } while(0)
  
void *(*_malloc)(unsigned long s) = malloc;
void *example = (void *)"hi";

void *m(unsigned long XARG){
    if(XARG == 1) 
      return example; 
    else 
      return NULL;
}

#define malloc(XARG) m(XARG) 

int main(){

  exit_called = 0;
  xok_zero(0);
  printf("%s xok_zero 0 passes\n", exit_called == 0 ? "PASS" : "FAIL");

  xok_zero(1);
  exit_called = 0;
  xok_zero(0);
  printf("%s xok_zero 1 fails\n", exit_called == 1 ? "PASS" : "FAIL");

  xok_gt(0);
  xok_gt(10);
  xok_gt(-1);
  void *x;
  xok_not_null(x = malloc(1));
  xok_not_null(x = malloc(10));
  char *a = "alpha bravo charlie delta echo";
  char *b = "foxtrot golf hotel india juliet";
  char *c = xdup(a, strlen(a));
  xok_zero(strncmp(a, c, strlen(a)));
  char *d = xdupstr(b);
  xok_zero(strncmp(b, d, strlen(b)));
  
}
