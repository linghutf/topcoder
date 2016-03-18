#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdlib>
#include <ctime>

using namespace std;

void generate_N(std::vector<int> &v,int n)
{
	srand(time(NULL));
	for(int i=0;i<n;++i)
		v.push_back(rand()%100);
}

int main(int argc, char const *argv[])
{
	auto cmp = [](int a,int b){return b-a;};
	vector<int> v;
	int n = 20;
	generate_N(v,n);

	std::make_heap(v.begin(),v.end());

	std::for_each(v.begin(),v.end(),[](int n){cout<<n<<'\t';});
	cout<<endl;
	return 0;
}