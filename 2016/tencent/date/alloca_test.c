/*
 * alloca_test.c
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "alloca_test.h"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

int main(int argc,char const *argv[])
{
    char *p = (char*)alloca(1<<20);
    strcpy(p,"hello");
    printf("%s\n",p);
    return 0;
}
