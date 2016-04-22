#!/bin/awk

BEGIN{FS = ":"}
{
    cnt+=$2;
    printf("%3d:%4d\n",$1,$2);
}
END{
    printf("total:%4d\n",cnt);
}
