#ifndef BFORMAT_H_
#define BFORMAT_H_

#define BPRINT(n) \
    while(n){\
        if((n)&1)\
        printf("1");\
        else\
        printf("0");\
        (n)=(n)>>1;\
    }
#endif
