#include <stdio.h>

int main(int argc, char *argv[])
{
    int i,j,k;
    int a = 1500,b = 2000;

    for(k=a/11;k<=b/11;++k)
    {
        for(j=a/7;j<=b/7;++j)
        {
            for(i=a/5;i<=b/5;++i)
            {
                int t1 = k*11+6;
                int t2 = j*7+4;
                int t3 = i*5+3;
                if(t1==t2 && t2==t3)
                    printf("%d\n",t1);
            }
        }
    }
    return 0;
}
