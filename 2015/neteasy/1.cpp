#include <iostream>
#include <algorithm>
#include <cinttypes>
using namespace std;

uint64_t gcd(uint64_t a,uint64_t b);

uint64_t fight(uint64_t val,uint64_t *a,int n);

int main(int argc, char const *argv[])
{
	uint64_t val,n;
	cin>>n>>val;
	if(n<1||n>100000)
		return -1;
	uint64_t *p = new uint64_t[n];
	if(p==NULL)
		return -1;

	for(int i=0;i<n;++i)
		cin>>p[i];
	cout<<fight(val,p,n)<<endl;
	return 0;
}

uint64_t gcd(uint64_t a,uint64_t b)
{
	if(a<b)
		swap(a,b);
	while(a%b!=0){
		a%=b;
		swap(a,b);
	}
	return b;
}

uint64_t fight(uint64_t val,uint64_t *a,int n)
{
	for(int i=0;i<n;++i){
		if(val>=a[i]){
			val+=a[i];
		}else{
			val+=gcd(val,a[i]);
		}
	}
	return val;
}