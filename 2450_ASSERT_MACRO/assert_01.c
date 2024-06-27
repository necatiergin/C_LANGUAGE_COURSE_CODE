//sample assert macro implementation

#include <stdio.h>

#ifndef NDEBUG
#define ASSERT(EXPR) (                        \
  (EXPR) ? (void)0 : (                        \
    printf("%s:%d: failed assertion '%s'\n",  \
      __FILE__, __LINE__, #EXPR               \
    ),                                        \
    abort()                                   \
  ))
#else
#define assert(EXPR)  ((void)0)
#endif /* NDEBUG */
