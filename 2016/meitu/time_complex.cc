/**
 *  时间复杂度
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int func1(int n)
{
	int i,j;
	int sum=0;
	for(i=0;i<n;i*=2)
		for(j=i/2;j<i;++j)
			sum+=j;
	return sum;
}

int func2(int n)
{
	int i,j;
	int sum = 0;
	for(i=0;i<n;++i)
		for(j=0;j<n;++j);
}

//2^n * log(n)
double r(int n)
{
	return log(n)*pow(2,n)/log(2);
}

int main(int argc, char const *argv[])
{
	int n = atoi(argv[1]);
	cout<<func1(n)/r(n)<<endl;
	
	return 0;
}