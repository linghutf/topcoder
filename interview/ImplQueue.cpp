#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

template<typename T> class CQueue{
    public:
        CQueue(void){}
        ~CQueue(void){}

        void appendTail(const T &node);
        T deleteHead();

    private:
        //stack1作为入队，stack2作为出队
        std::stack<T> stack1;
        std::stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead()
{
    //T data=NULL;//不建议这种方式表示空，参展stl stack为空弹出则宜常
    //如果stack2有数据直接弹出
    /*
    if(!stack2.empty()){
        data = stack2.top();
        stack2.pop();
    }else{
        //从stack1加入staks2,再弹出就是头部
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        data = stack2.top();
        stack2.pop();
    }
    */
    //简化版
    if(stack2.empty()){
        //从stack1加入staks2,再弹出就是头部
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    if(stack2.empty())
        throw std::runtime_error("queue is empty.");//std::exception::what();
    T data = stack2.top();
    stack2.pop();
    return data;//stack1,stack2为空,则异常
}

int main(int argc, char *argv[])
{
    CQueue<int> c;
    c.appendTail(12);
    c.appendTail(13);
    c.appendTail(14);
    cout<<c.deleteHead()<<endl; //12
    c.appendTail(15);
    cout<<c.deleteHead()<<endl; //13
    cout<<c.deleteHead()<<endl; //14
    cout<<c.deleteHead()<<endl; //15
    c.appendTail(16);
    cout<<c.deleteHead()<<endl; //16
    cout<<c.deleteHead()<<endl; //异常

    return 0;
}
