#include <iostream>
#include <bitset>
#include <ctime>
#include <iomanip>
using namespace std;

int main(){
    const int N = 2000000;
    clock_t s = clock();
    bitset<N+1> b;
    int cnt = 0;
    b.set(0);
    b.set(1);
    b.flip();
    int i=2;
    int k;
    while(i*i<=N){
        if(b.test(i)){
            cnt++;
            k = i<<1;
            while(k<=N){
                b.reset(k);
                k+=i;
            }
        }
        i++;
    }
    while(i<=N){
        if(b.test(i))
            cnt++;
        i++;
    }
    clock_t e = clock();
    double millis = 1000.0*(e-s)/CLOCKS_PER_SEC;
    cout<<cnt<<" primes.\n"<<millis<<" ms."<<endl;
/*
    for(int i=0;i<=N;++i){
        if(b.test(i))
            cout<<setw(4)<<i;
    }
    cout<<endl;
*/
    return 0;
}
