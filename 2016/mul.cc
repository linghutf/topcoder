#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int result[2048]={0};

int main(int argc, char const *argv[])
{
	string num1,num2;
	num1 = argv[1];
	num2 = argv[2];

	//std::reverse(num1.begin(),num1.end());
	//std::reverse(num2.begin(),num2.end());
	int neg = 1;

	int len1 = num1.size();
	int len2 = num2.size();
	//neg number
	if(num1.at(0)=='-'){
		neg = -neg;
		len1--;
	}
	if(num2.at(0)=='-'){
		neg = -neg;
		len2--;
	}
	//string::reverse_iterator itp,itq;
	int i,j;
	for(i=len2-1;i>=0;--i){
		for(j=len1-1;j>=0;--j){
			result[len2-i+len1-j-2] += (num1[i]-'0')*(num2[i]-'0');
		}

	}

	for(i=0;i<len1+len2;++i){
		if(result[i]>=10){
			result[i+1]+=result[i]/10;
			result[i]%=10;
		}
	}
	
	while(result[i]!=0){
		result[i+1]+=result[i]/10;
		result[i++]%=10;
		//++i;
	}
	int len = i-1;

#ifdef RESULT_REVERSE
	std::reverse(result,result+len);
	for(i=0;i<len;++i){
		cout<<result[i];
	}
	cout<<endl;
#endif
	//or
	if(neg==-1)
		result[len-1]=-result[len-1];
	
	for(i=len-1;i>=0;--i){
		cout<<result[i];
	}
	cout<<endl;
	return 0;
}