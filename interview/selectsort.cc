#include <iostream>
#include <algorithm>

using namespace std;

void selectSort(int a[],size_t len)
{
    if(a==NULL) return;
    size_t i,j;
    for(i=0;i<len;++i){
        int min = i;
        for(j = i+1;j<len;++j)
            if(a[j]<a[min]) min =j;//找到在i之后最小的数
        std::swap(a[i],a[min]);//将最小的数放在该位置
    }
}

void insertSort(int a[],size_t len)
{
    size_t i,j;
    for(i=1;i<len;++i){
        for(j=i;j>0 && a[j]<a[j-1];--j){//从后往前依次插入
            std::swap(a[j],a[j-1]);
        }
    }
}

void testcase()
{
    int a[]={1};
    selectSort(a,1);

    int b[]={3,-1,2};
    //selectSort(b,3);
    insertSort(b,3);
    cout<<b[0]<<','<<b[1]<<','<<b[2]<<endl;
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
