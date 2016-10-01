#include <iostream>
#include <vector>

template<typename T>
class stack{
    public:
        stack(){}

        void push(const T& ele)
        {
            _data.push_back(ele);
            if(_link2NextMaxs.empty())
            {
                _link2NextMaxs.push_back((_data.end()-1));
            }
            else// 找到插入位置
            {
                for(typename std::vector<typename std::vector<T>::iterator>::iterator it=_link2NextMaxs.begin();
                        it!=_link2NextMaxs.end();++it)
                {
                    // why visit 0
                    std::cout<<"visit:"<<**it<<std::endl;
                    if(ele<**it)
                    {
                        std::cout<<"insert:"<<**it<<std::endl;
                        _link2NextMaxs.insert(it,_data.end()-1);
                        break;
                    }
                }
            }
        }

        void pop()
        {
            if(!_data.empty())
            {
                for(typename std::vector<typename std::vector<T>::iterator>::iterator it=_link2NextMaxs.begin();
                        it!=_link2NextMaxs.end();++it)
                {
                    if(*it == _data.end()-1)
                    {
                        _link2NextMaxs.erase(it);
                        break;
                    }
                }
                _data.pop_back();
            }
        }

        T max()
        {
            return **(_link2NextMaxs.end()-1);
        }

        T top()
        {
            return *(_data.end()-1);
        }

        bool empty()
        {
            return _data.empty();
        }

    private:
        std::vector<T> _data;
        // 从小到大存放指针
        std::vector<typename std::vector<T>::iterator> _link2NextMaxs;
};

int main(int argc, char *argv[])
{
    stack<int> s;
    int n = 10;
    s.push(n--);
    s.push(n--);
    s.push(n--);
    s.pop();
    std::cout<<"top:"<<s.top()<<",max:"<<s.max()<<std::endl;
    return 0;
}
