#include <iostream>
#include <queue>

using namespace std;

template<typename T> class CStack{
    public:
        CStack(){}
        ~CStack(){}

        void EnQueue(const T& element);
        T DeQueue();

    private:
        std::queue<T> q1;
        std::queue<T> q2;
};

template<typename T> void CStack<T>::EnQueue(const T &element)
{
    if(q2.empty())
        q1.push(element);
    else if(q1.empty())
        q2.push(element);
    else
        throw std::runtime_error("stack internal error.");
    //std::queue<int> q;
}

template<typename T> T CStack<T>::DeQueue()
{
    if(q1.empty() && q2.empty())
        throw std::runtime_error("stack is empty.");

    T data;
    if(q1.empty()){
        //转移数据到q1
        while(q2.size()!=1){
            q1.push(q2.front());
            q2.pop();
        }
        data = q2.front();
        q2.pop();
    }else{
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        data = q1.front();
        q1.pop();
    }
    return data;
}

int main(int argc, char *argv[])
{
    CStack<int> s;
    s.EnQueue(10);
    s.EnQueue(11);
    cout<<s.DeQueue()<<endl;//11
    s.EnQueue(12);
    cout<<s.DeQueue()<<endl;//12
    cout<<s.DeQueue()<<endl;//10
    cout<<s.DeQueue()<<endl;//error


    return 0;
}
