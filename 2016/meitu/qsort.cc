#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(int a[],int low,int high)
{
	int i=low,j=high+1;
	int privote = a[low];
	while(true){
		while(a[++i]<privote){
			if(i==high) break;
		}
		while(a[--j]>privote){
			if(j==low) break;
		}
		if(i>=j) break;
		std::swap(a[i],a[j]);
	}
	std::swap(a[j],a[low]);
	return j;
}

void quicksort(int a[],int low,int high)
{
	if(low>=high) return;
	int index = partition(a,low,high);
    for_each(a+low,a+high+1,[](int n){cout<<n<<'\t';});
    cout<<endl;

	quicksort(a,low,index-1);
	quicksort(a,index+1,high);
}

void Qsort(int a[],int len)
{
	quicksort(a,0,len-1);
}

void generate_n(int a[],int nums)
{
	srand(time(NULL));
	for(int i=0;i<nums;++i){
		a[i]=rand()%100;
	}
}

void testcase()
{
    cout<<"每趟排序:"<<endl;
    int a[]={19,15,12,18,21,36,45,10};
    int len = sizeof(a)/sizeof(a[0]);
    Qsort(a,len);
    cout<<endl;
}
int main(int argc, char const *argv[])
{
	int len = 12;
	int a[12];
	generate_n(a,len);
	for_each(a,a+len,[](int n){cout<<n<<'\t';});
	cout<<endl;

	Qsort(a,len);
	for_each(a,a+len,[](int n){cout<<n<<'\t';});
	cout<<endl;

    testcase();
	return 0;
}
