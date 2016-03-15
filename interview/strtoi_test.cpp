#include <iostream>
#include <string>

#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

int mystrtoi(const char *str)
{
    int len = strlen(str);
    int num=0,flag=1;
    if(str==NULL|| len==0)
        return num;

    int i=0;
    //如果是负数
    if(str[0]=='-'){
        flag=-1;
        i=1;
    }
    int tmp;
    for(;i<len;++i){
        if(std::isdigit(str[i])){
            tmp = str[i]-'0';
            num = num*10+tmp;
        }else{//不是数字
            break;
        }
    }
    return flag==1?num:-num;
}

void testcase()
{
    const int n = 6;
    char str[][10]={
        "--1234",//错误
        "a",
        "-0",
        "1a2c",
        "12-3",
        ""
    };
    /*
    std::string str1;//""

    cout<<"\"\" test:"<<stoi(str1)<<endl;//不接受空字符串
    */
    for(int i=0;i<n;++i)
        cout<<atoi(str[i])<<","<<mystrtoi(str[i])<<endl;
        //cout<<stoi(std::string(str[i]),nullptr,10)<<endl;
}
int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
