#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "crowx.c"

#define exit(x) \
  fprintf(stderr, "exit called for %d\n", x)

int main(){

  xok(0);
  xok(1);
  xokgt(0);
  xokgt(10);
  xokgt(-1);
  
  /* xok success */;
  /* xok failure (subp) with line number */
  /* xprtok success */
  /* xptrok fail with line number */
  /* xdup */
  /* xdupstr */
  /* compile custom errlog function */
}
