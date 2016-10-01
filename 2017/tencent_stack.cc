/**
 * 使用一个序列记住大小关系
 *
 */

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

template<typename T>
class Stack{
    public:
        Stack():_max(_data.end()),_sec(_data.end()){}
        virtual ~Stack(){}

        void push(const T & ele)
        {
            _data.push_back(ele);
            if(_max==_data.end())// initialize
            {
                _max = _data.begin();
            }else if(*_max<ele)
            {
                _sec = _max;
                _max = _data.end()-1;
            }
        }

        void pop()
        {
            if(!_data.empty())
            {
                if(_data.size()==1)
                {
                    _max = _data.end();//null
                    _sec = _max;
                }
                else if(_max==_data.end()-1)//top
                {
                    _max = _sec;//并没有更新_sec

                }
                _data.pop_back();
            }
        }

        const T top() const
        {
            if(!_data.empty())
            {
                return *_data.rbegin();
            }
            throw std::exception();
        }

        typename std::vector<T>::iterator max()
        {
            return _max;
        }

        typename std::vector<T>::iterator end()
        {
            return _data.end();
        }

    private:
        std::vector<T> _data;
        //std::vector<T> _record;
        typename std::vector<T>::iterator _max;
        typename std::vector<T>::iterator _sec;
};

int main(int argc, char *argv[])
{
    Stack<int> s;
    int n = 10;
    s.push(n--);
    s.push(n--);
    s.pop();
    printf("top:%d,max:%d\n",s.top(),s.max()!=s.end()?*s.max():-1);
    // 段错误
    /*
    std::stack<int> ss;
    std::cout<<"empty stack:"<<ss.top()<<std::endl;
    */
    return 0;
}
