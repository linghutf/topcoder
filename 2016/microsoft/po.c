/*
 * po.c
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "po.h"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(char *p)
{
    p=p+1;
}
int main(int argc,char const *argv[])
{
   char s[]="1234";
   func(s);
   printf("%c\n",s[0]);

   char p[30]={"a","b","c"};

   return 0;
}
