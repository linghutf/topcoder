/**
 * 查看保存指针的队列在弹出之后
 * 地址有没有改变
 * 结论：没有改变
 */

#include <cstdio>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    std::queue<int *> q;
    int a[]={3,1,2};
    q.push(&a[0]);
    int *p = q.front();
    printf("src addr:%p,front addr:%p\n",a,p);
    q.pop();
    printf("after pop:%p\n",p);
    return 0;
}
