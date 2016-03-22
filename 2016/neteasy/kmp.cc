#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
//#include <vector>

using namespace std;

//static int errno = 0;

void GetNext(int next[],const char *s)
{
	if(s==NULL) return;
	int j=0,k=-1;
	next[j]=k;
	int len = strlen(s);
	if(len==0) return;
	while(j<len){
		if(k==-1||s[j]==s[k]){
			j++;
			k++;
			if(s[j]==s[k])
				next[j]=next[k];
			else
				next[j]=k;
		}else{//mark return back
			k = next[k];
		}
	}
}

int Kmp(const char *s,const char *t)
{
	int times = 0;
	if(s==NULL||t==NULL) return times;
	int lens = strlen(s);
	int lent = strlen(t);
	if(lent==0) return times;
	int i=0,j=0;
	int *next = new int[lent];
	if(next==NULL){
		errno = -1;
		return times;
	}
	GetNext(next,t);

	while(i<lens){
		if(j==-1||s[i]==t[j]){
			i++;
			j++;
			if(j==lent){//完成一次匹配
				//j=0;//不重新开始
				times++;
			}
		}else{
			j=next[j];
		}
	}
    delete[] next;
	return times;
}

void testcase()
{
	char a[][20]={
		"HAHAHA","WQN","ADADADA","BABABABABABABABABB","ADDAADAADDAAADAAD"
	};
	char b[][20]={
		"HA","WQN","ADA","BABABB","DAD"
	};
	int n = 5;
	//a[2]:3 times
	for(int i=0;i<n;++i){
		std::cout<<Kmp(a[i],b[i])<<std::endl;
	}

}
int main(int argc, char *argv[])
{
	//testcase();
	int n;
	cin>>n;

	string s[20],t[20];
	//string ss(1000000),tt(10000);
	if(n<=20 && n>=1){
		for(int i=0;i<n;++i){
			cin>>t[i]>>s[i];
		}

		for(int i=0;i<n;++i){
			cout<<Kmp(s[i].c_str(),t[i].c_str())<<endl;
		}
	}
	return 0;
}
