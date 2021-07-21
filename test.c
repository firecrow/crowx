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

char PASS[] = "\x1b[32mPASS\x1b[0m";
char FAIL[] = "\x1b[31mFAIL\x1b[0m";

int main(){

  exit_called = 0;
  xok_zero(0);
  printf("%s xok_zero 0 passes\n", exit_called == 0 ? PASS : FAIL);

  exit_called = 0;
  xok_zero(1);
  printf("%s xok_zero 1 fails\n", exit_called == 1 ? PASS : FAIL);

  exit_called = 0;
  xok_gt(0);
  printf("%s xok_gt 0 passes\n", exit_called == 0 ? PASS : FAIL);

  exit_called = 0;
  xok_gt(10);
  printf("%s xok_gt 10 passes\n", exit_called == 0 ? PASS : FAIL);

  exit_called = 0;
  xok_gt(-1);
  printf("%s xok_gt -1 fails\n", exit_called == 1 ? PASS : FAIL);

  void *x;
  exit_called = 0;
  xok_not_null(x = malloc(1));/* magic number from override define */
  printf("%s xok_not_null magic number passes\n", exit_called == 0 ? PASS : FAIL);

  exit_called = 0;
  xok_not_null(x = malloc(10));
  printf("%s xok_not_null not magic number fails\n", exit_called == 1 ? PASS : FAIL);
}
