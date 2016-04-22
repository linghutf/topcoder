#include <iostream>

#include <cmath>

using namespace std;

struct Factor{
    long a;
    long b;
    Factor(long a_,long b_=1):a(a_),b(b_){}
};

class Possible{
    public:
        Possible(float a=0):a_(a_){}
        static Factor C(int m,int n)
        {
            Factor fa(1,1);
            int i;
            for(i=0;i<m;++i){
                fa.a*=(n-i);
                fa.b*=(n-i);
            }
            for(;i<n;++i){
                fa.b*=(n-i);
            }
            return fa;
        }

        double possiblity(int m,int n)
        {
            Factor f = Possible::C(m,n);
            return f.a*pow(a_,m)*pow(1-a_,n-m)/f.b;
        }
    private:
        float a_;
};

int main()
{
    Possible p(0.005);
    int n=10;
    double result = 0;
    for(int i=1;i<=n;++i)
        result+=p.possiblity(i,n);

    cout<<result<<endl;
    return 0;
}
