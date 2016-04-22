#include <stdio.h>

struct base{
    int a;
    void (*say)(int);
};

struct base* init_base(struct base *b,int a_,void (*func)(int))
{
    if(b==NULL) return b;
    b->a = a_;
    b->say = func;
    return b;
}

struct derived{
    struct base *ba;
    void (*say)(struct base*);
};

struct derived* init_derived(struct derived *d,struct base *b_,void (*func)(struct base*))
{
    if(d==NULL) return d;
    d->ba = b_;
    d->say = func;
    return d;
}

void func(int a)
{
    printf("a:%d\n",a);
}

void func_2(struct base *b)
{
    printf("struct a:%d\n",b->a);
}

int main()
{

    struct derived d;
    struct base b;
    init_base(&b,10,func);
    init_derived(&d,&b,func_2);
    d.ba=&b;
    (d.ba)->say(b.a);
    d.say(&b);

    return 0;
}
