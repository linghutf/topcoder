/**
 * 测试set和hashset能否接收char*数据
 * 结论：可以插入
 * 因此不必使用 string作为中转
 */
#include <iostream>
#include <set>
#include <unordered_set>
#include <functional> //std::hash c++11

#include <cstring>
#include <string>

//#include <boost/hash.hpp>

using namespace std;

//比较char*
struct Key_Compare{
    bool operator()(char *s,char *t){
        return strcmp(s,t);
    }
};

//char* Hash
//自定义hash模型
/*struct Key_Hash{
    using boost::hash
};*/
namespace std{
    template<> struct hash<char*>:public unary_function<char*,size_t>{
        size_t operator()(const char *s) const{
            std::hash<char*> pHash;
            if(s==NULL) return pHash(s);//hash地址
            int len = strlen(s);
            if(len==0) return pHash(s);

            std::hash<char> cHash;
            size_t h=cHash(s[0]);//hash字符串
            for(int i=1;i<len;++i)
                h^=cHash(s[i]);//hash字符,异或
            cout<<"hash:"<<h<<endl;
            return h;

        }
    };

    //自定义相等,特化函数
    template<> struct equal_to<char*>:public binary_function<char*,char*,bool>{
        bool operator()(char *s,char *t){
            return strcmp(s,t);
        }
        //typedef char* first_argument_type;
        //typedef char* second_argument_type;
        //typedef bool result_type;
    };

    template<> struct less<char*>:public binary_function<char*,char*,bool>{
        bool operator()(char *s,char *t){
            return strcmp(s,t)<0;
        }
    };
}

int main(int argc, char *argv[])
{
    char str[]="99xxx";
    char *p = str;//测试指针插入
    char str2[10];//测试不同地址，相同内容插入
    strncpy(str2,str,strlen(str));

    //没有使用自定义compare,有重复
    std::set<char*> s;
    s.insert(str);
    s.insert(p);//认为是相同值，插入无效
    s.insert(str2);//认为是不同值，可以插入，因此需要自定义Compare=
    cout<<"有序set:"<<endl;
    for(auto &it:s)
        cout<<it<<endl;

    //使用自定义比较函数，消除重复
    std::set<char*,Key_Compare> s2;
    s2.insert(str);
    s2.insert(p);
    s2.insert(str2);
    cout<<"有序set(自定义compare):"<<endl;
    for(auto &it:s2)
        cout<<it<<endl;

    //没有使用自定义hash函数，有重复
    std::unordered_set<char*> se;
    se.insert(str);
    se.insert(str2);//认为和str是不同的值,必须自定义hash算法
    se.insert(p);
    cout<<"hashset:"<<endl;
    for(auto &it:se)
        cout<<it<<endl;

    //使用自定义hash函数，无重复
    std::unordered_set<char*,std::hash<char*>,std::equal_to<char*> > se2;
    se2.insert(str);
    se2.insert(str2);//认为和str是不同的值,必须自定义hash算法
    se2.insert(p); //相同
    cout<<"hashset(自定义hash):"<<endl;
    for(auto &it:se2)
        cout<<it<<endl;

    //使用string,默认实现了compare和hash,无重复，但是插入时构造对象比较浪费
    unordered_set<string> m;
    m.insert(string(str));
    m.insert(string(p));//都是相同值，因为使用string可以避免插入重复值
    m.insert(string(str2));
    cout<<"hashset(string):"<<endl;
    for(auto &it:m)
        cout<<it<<endl;

    return 0;
}
