#include <iostream>
#include <algorithm>
#include <list>
#include <memory>
#include <array>
using namespace std;

template<typename K,typename V>class HashMap{
    public:
        static const int BUCKET_SIZE = 10;
    private:
        typedef typename std::list<std::shared_ptr<V>> Container;
        typedef typename Container::iterator Iterator;
        typedef typename std::array<Iterator,BUCKET_SIZE> Bucket;

    public:
        HashMap();
        virtual ~HashMap();

    public:
        std::pair<bool,Iterator> insert(std::pair<K,V> element);

    private:
        Bucket bucket_;
};

template<class K,class V>
HashMap<K,V>::HashMap()
{
    for(int i=0;i<HashMap::BUCKET_SIZE;++i){
        this->bucket_[i]=new std::list<std::shared_ptr<V>>();
    }
}

template<class K,class V>
HashMap<K,V>::~HashMap()
{
    for(int i=0;i<HashMap::BUCKET_SIZE;++i){
        delete this->bucket_[i];
    }
}

template<class K,class V>
std::pair<bool,Iterator> HashMap<K,V>::insert(std::pair<K,V> element)
{
}
int main()
{
    return 0;
}
