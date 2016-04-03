/**
 *
 * 大数乘法
 */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int result[2048]={0};

bool g_fail = false;
//返回false代表失败
void mulBigInt(string &num1,string &num2,int &len)
{
    len = 0;
    //判断0的情况
    if(num1.compare("0")==0||num1.compare("-0")==0||num2.compare("0")==0||num2.compare("-0")==0){
        len = 1;
        return;
    }
	int neg = 1;

	int len1 = num1.size();
	int len2 = num2.size();
    int end1 = 0,end2=0;
	//neg number
	if(num1.at(0)=='-'){
		neg = -neg;
		end1 = 1;
	}
	if(num2.at(0)=='-'){
		neg = -neg;
		end2 = 1;
	}
	//string::reverse_iterator itp,itq;
	int i,j;
    char a,b;
	for(i=len2-1;i>=end2;--i){
		for(j=len1-1;j>=end1;--j){
            a=num1[j];
            b=num2[i];
            if(!(isdigit(a)&&isdigit(b))){
                cout<<"ERROR number."<<endl;
                g_fail = true;
                return;
            }
			result[len2-i+len1-j-2] += (num1[j]-'0')*(num2[i]-'0');
		}
	}

	for(i=0;i<len1+len2-end1-end2;++i){
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
	len = i-1;

#ifdef RESULT_REVERSE
	std::reverse(result,result+len);
	for(i=0;i<len;++i){
		cout<<result[i];
	}
	cout<<endl;
#endif
    //符号保存在高位数位中
	if(neg==-1)
		result[len-1]=-result[len-1];

}

void printBigInt(int *a,int len)
{
	for(int i=len-1;i>=0;--i){
		cout<<result[i];
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	string num1,num2;
	num1 = argv[1];
	num2 = argv[2];

    int result_len;
    mulBigInt(num1,num2,result_len);
    printBigInt(result,result_len);

	return 0;
}
