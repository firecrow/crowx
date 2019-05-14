#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "crowx.c"

#define exit(XARG) \
  fprintf(stderr, "exit called for %d\n", XARG)
  
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

  xok(0);
  xok(1);
  xokgt(0);
  xokgt(10);
  xokgt(-1);
  void *x;
  xokptr(x = malloc(1));
  xokptr(x = malloc(10));
  char *a = "alpha bravo charlie delta echo";
  char *b = "foxtrot golf hotel india juliet";
  char *c = xdup(a, strlen(a));
  xok(strncmp(a, c, strlen(a)));
  char *d = xdupstr(b);
  xok(strncmp(b, d, strlen(b)));
  
}
