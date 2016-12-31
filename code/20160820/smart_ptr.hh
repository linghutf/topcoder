#ifndef __SMART__POINTER__H__
#define __SMART__POINTER__H__

#include <mutex>

template<typename T>
class smart_ptr{
    private:
        T* _p;
        size_t * _refs;
        std::mutex _mtx;

        // 引用计数减少1
        void _clear()
        {
            if(!--*_refs)
            {
                delete _p;
                _p=NULL;
                delete _refs;
                _refs=NULL;
            }
        }

    public:
        smart_ptr(T * p = NULL):_p(p),_refs(new size_t(1)){}

        smart_ptr(const smart_ptr<T> & rhs):
            _p(rhs._p),_refs(rhs._refs){
                ++*_refs;
            }

        virtual ~smart_ptr()
        {
            _mtx.lock();
            _clear();
            _mtx.unlock();
        }

        smart_ptr<T> & operator=(const smart_ptr<T> & rhs)
        {
            // 清理自己的状态
            if(this!=&rhs)
            {
                _mtx.lock();
                _clear();
                _p = rhs._p;
                _refs = rhs._refs;
                ++*_refs;// add
                _mtx.unlock();
            }
            return *this;
        }

        smart_ptr<T> & operator=(T * p)
        {
            if(_p != p){
                _mtx.lock();
                _clear();//减少当前的引用计数
                _p = p;// 重新申请
                _refs = new size_t(1);
                _mtx.unlock();
            }
            return *this;
        }

        T & operator*()
        {
            return *_p;
        }

        const T & operator*() const
        {
            return *_p;
        }

        T * operator->()
        {
            return _p;
        }

        const T * operator->() const
        {
            return _p;
        }

        size_t use_count()
        {
            return *_refs;
        }

};

#endif
