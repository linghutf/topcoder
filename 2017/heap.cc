#ifndef HEAP__H__
#define HEAP__H__

#include <mutex>
#include <algorithm>
#include <vector>

template<typename T,typename Pred>
class ConcurrentHeap{
    public:
        ConcurrentHeap():_pred(Pred()){}

    public:
        void add(const T & obj)
        {
            _mtx.lock();
            _items.push_back(obj);
            std::push_heap(_items.begin(),_items.end(),_pred);
            _mtx.unlock();
        }

        bool remove(const T & obj)
        {
            _mtx.lock();
            bool ret = false;
            for(auto it = _items.begin();_item.end();++it)
            {
                if(*it == obj)
                {
                    _items.erase(it);
                    std::make_heap(_items.begin(),_items.end(),_pred);
                    ret = true;
                    break;
                }
            }
            _mtx.unlock();
            return ret;
        }

    private:
        std::mutex _mtx;
        std::vector<T> _items;
        Pred _pred;
};

#endif
