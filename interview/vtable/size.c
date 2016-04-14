/*
 * size.c
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "size.h"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char const *argv[])
{
   int n;//4byte
   int *p;//8byte
   printf("%d,%d\n",sizeof(n),sizeof(p));
   return 0;
}
