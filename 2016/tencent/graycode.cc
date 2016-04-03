/**
 *在一组数的编码中，若任意两个相邻的代码只有一位二进制数不同，
 则称这种编码为格雷码(Gray Code)，请编写一个函数，
 使用递归的方法生成N位的格雷码。
 给定一个整数n，请返回n位的格雷码，顺序为从0开始。i
 *
 * 1 => 0 1
 * 2 => 00 01 11 10
 * 3 => 000 001 011 010 110 111 101 100
 */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class GrayCode{
public:
    vector<string> getGray(int n){
        vector<string> vec;
        if(n==1){
            vec.push_back("0");
            vec.push_back("1");
        }else{
            vector<string> v = getGray(n-1);
            for(vector<string>::iterator it = v.begin();it!=v.end();++it){
                vec.push_back("0"+*it);
            }
            for(vector<string>::reverse_iterator it = v.rbegin();it!=v.rend();++it){

                vec.push_back("1"+*it);
            }
        }
        return vec;
    }
};

int main(int argc, char *argv[])
{
    GrayCode c;
    auto v = c.getGray(3);
    for_each(v.begin(),v.end(),[](auto &s){cout<<s<<endl;});
    return 0;
}
