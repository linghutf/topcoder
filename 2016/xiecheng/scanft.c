/*
 * scanft.c
 * Copyright (C) 2016 linghutf <linghutf@pc>
 *
 * Distributed under terms of the MIT license.
 */

/*
 * if it is project,may write by this way.
 * but,now I just want to write simple small file.:)
 * #include "scanft.h"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char const *argv[])
{
    int a;
    float b,c;
    scanf("%2d%3f%4f",&a,&b,&c);
    printf("%d,%d,%f\n",a,b,c);
    return 0;
}
