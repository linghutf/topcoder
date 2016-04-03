/**
 * 数字字符串找到最大的递增序列
 *
 * 思路:都是等长则返回第一个
 *
 * 时间复杂度O(n)
 * 空间复杂度O(n)
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
bool g_null = false;
bool g_nofound = false;

std::string MaxIncSeq(char *str)
{
    string s="";
    if(str==NULL){
        g_null=true;
        return s;
    }
    int len = strlen(str);
    if(len==0){
        g_null=true;
        return s;
    }

    std::vector<string> ump;

    int start = 0,end = 1;
    int cnt=1;
    //统计递增序列
    while(end<=len){
        if(str[end-1]<str[end]){
            cnt++;
            end++;
        }else{
            ump.push_back(string(str+start,str+end));//]=cnt;
            start = end;//下一个序列
            end++;
            cnt=1;//重新计数
        }
    }

    //找到最长递增序列
    int maxlens = 0;
    std::vector<std::string>::iterator it,maxit=ump.end();
    for(it=ump.begin();it!=ump.end();++it){
        if(it->length()>maxlens){
            maxlens = it->length();
            maxit = it;
        }
    }

    if(maxit!=ump.end()) return *maxit;

    g_nofound = true;
    return s;
}

void __test(char *str)
{
    cout<<MaxIncSeq(str)<<endl;
    if(g_null||g_nofound){
        cout<<"ERROR in test-1!"<<endl;
    }
}

void testcase()
{
    char p[]="28953456323";
    char str[]="1234";
    __test(p);
    __test(str);

    char p1[]="21";
    __test(p1);

    char p2[]="";
    __test(p2);
}

int main(int argc, char *argv[])
{
    testcase();

    return 0;
}
