#ifndef HASHMAP_HH_
#define HASHMAP_HH_
#include <list>
#include <vector>
#include <memory>

#define BUCKET_SIZE 10

template<typename K,typename V>class HashMap{
    public:
typedef typename std::list<std::shared_ptr<V>> LinKMap;
typedef typename LinkMap::iterator Iterator;
        HashMap();
    private:
        std::vector<Iterator> map_;
};

#endif
