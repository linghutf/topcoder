#include <iostream>
#include <stack>
// 每次获取栈底元素
int pop_buttom(std::stack<int> & st)
{
    int top = st.top();//相当于栈，暂存变量
    st.pop();
    if(st.empty())
    {
        return top;
    }
    else
    {
        // 递归获取
        // 当栈为空时，返回栈底元素
        int bottom = pop_buttom(st);
        st.push(top);
        return bottom;
    }
}

void reverse(std::stack<int> & st)
{
    if(st.empty())
    {
        return;
    }

    int bottom = pop_buttom(st);
    // 递归依次获取栈底元素，1,2,3,4,5
    // 其余元素都按照原顺序在栈中
    // bottom: 1 , stack: 5,4,3,2
    // bottom: 2 , stack: 5,4,3
    // ...
    // bottom: 5 , stack: nil
    reverse(st);

    // 5,4,3,2,1依次入栈返回
    st.push(bottom);
}

int main(int argc, char *argv[])
{
    std::stack<int> s;
    for(int i=5;i>=0;--i)
    {
        s.push(i);
    }

    reverse(s);

    while(!s.empty())
    {
        std::cout<<s.top()<<std::endl;
        s.pop();
    }
    return 0;
}
