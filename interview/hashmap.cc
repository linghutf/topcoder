#include <iostream>
#include <list>
#include <memory>
#include <array>
#include <algorithm>

using namespace std;
static const int BUCKET_SIZE = 10;

typedef int KeyType;
typedef int MappedType;

typedef std::list<std::shared_ptr<MappedType>> Container;
typedef Container::iterator Iterator;
typedef std::array<Container*,BUCKET_SIZE> Bucket;


class HashMap{
    public:

    public:
        HashMap();
        virtual ~HashMap();

    public:
        bool contains(std::pair<KeyType,MappedType>& element);

        std::pair<bool,Iterator> insert(std::pair<KeyType,MappedType>& element);
        MappedType& operator[](const KeyType& k);

    private:
        Bucket table_;
};

HashMap::HashMap()
{
    for(int i=0;i<BUCKET_SIZE;++i){
        Container *c = new std::list<std::shared_ptr<int>>();
        this->table_[i] = c;
    }
}

HashMap::~HashMap()
{
    for(int i=0;i<BUCKET_SIZE;++i){
        delete this->table_[i];
    }
}

bool HashMap::contains(std::pair<int,int>& element)
{
    int idx = element.first % BUCKET_SIZE;
    Container *c = this->table_[idx];
    return std::find_if(c->begin(),c->end(),[&](auto &n){return *n == element.second;})!=c->end();
}

std::pair<Iterator,bool> HashMap::insert(std::pair<int,int>& element)
{

    int idx = element.first % BUCKET_SIZE;
    Container *c = this->table_[idx];
    auto iter = std::find_if(c->begin(),c->end(),[&](auto &n){return *n == element.second;});
    if(iter==c->end()){//not found
        c->push_front(std::shared_ptr<int>(new int(element.second)));
        return std::make_pair(c->begin(),true);
    }else{
        bool ret = true;
        if(*(*iter) == element.second)
            ret = false;
        else
            *(*iter) == element.second;
        return std::make_pair(iter,ret);
    }
}

//通过key寻找到value
MappedType& HashMap::operator[](const KeyType& k)
{
    int idx = k%BUCKET_SIZE;
    Container *c = this->table_[idx];
    auto iter = std::find_if(c->begin(),c->end(),[&](auto &e){return }
}
int main()
{
    HashMap map;
    auto fi = std::make_pair(1,1);
    map.insert(fi);
    if(map.contains(fi))
        cout<<"test ok!"<<endl;
    fi.second = 3;
    auto res = map.insert(fi);
    cout<<**(res.second)<<endl;

    return 0;
}
