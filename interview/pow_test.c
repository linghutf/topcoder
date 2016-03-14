#include <stdio.h>
#include <math.h>

double PowerWithUnsignedExp(double base,unsigned int exp)
{
    if(exp == 0)
        return 1;
    if(exp == 1)
        return base;
    double result = PowerWithUnsignedExp(base,exp>>1);
    result *= result;
    if(exp & 0x1 ==1){
        result*=base;
    }
    return result;
}

void testcase1()
{
    double a[]={
        0,1,-1,0.5,1.3
    };
    int ex[]={
        0,-1,2,3,0.5
    };
    int len=5;
    for(int i=0;i<len;++i){
        printf("%lf^%d=%g\n",a[i],ex[i],pow(a[i],ex[i]));
        printf("%lf^%d=%g\n",a[i],ex[i],PowerWithUnsignedExp(a[i],ex[i]));
    }
}

int main(int argc, char *argv[])
{
    testcase1();
    return 0;
}
