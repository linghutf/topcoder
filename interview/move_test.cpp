#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<int> v={1,2,3,4};
	std::move(v.end()-3,v.end()-1,v.end());
	std::for_each(v.begin(),v.end(),[](auto i){cout<<i<<"\t";});
	cout<<endl;

	std::move_backward(v.begin()+1,v.begin()+3,v.end()+3);
	std::for_each(v.begin(),v.end(),[](auto i){cout<<i<<"\t";});
	
	cout<<endl<<std::accumulate(v.begin(),v.end(),10)<<endl;
	return 0;
}