/**
 * 自定义对象插入map
 * 保持唯一性
 */
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <functional>

#include <cstring>

using namespace std;

class Object{
    public:
        Object():id_(0),name_(NULL){}
        Object(int id,const char *name):id_(id){
            if(name==NULL) name_=NULL;
            else if(name_!=NULL) delete[] name_;
            else{
                int len = strlen(name);
                name_ = new char[len+1];
                strncpy(name_,name,len);
            }
        }
        int id(){return id_;}
        const char *name(){return name_;}
    private:
        int id_;
        char *name_;
};

namespace std{
    template<> struct hash<Object>{
        size_t operator()(const Object& obj)const{
            return std::hash<int>()(obj.id())^std::hash<char*>()(obj.name());
        }
    };

    template<> struct equal_to<Object>:public binary_function<Object,Object,bool>{
        bool operator()(const Object& a,const Object& b){
            if(a.id()-b.id()!=0){return a.id()<b.id();}
            return strcmp(a.name(),b.name());
        }
    };
}

void testcase()
{
    Object obj(1,"xxxd");
    unordered_map<Object,int> map;
    mao[obj]=1;

    unordered_map<Object,int>::iterator it;
    for(it=map.begin();it!=map.end();++it){
        cout<<it->first<<",num:"<<it->second<<endl;
    }
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
