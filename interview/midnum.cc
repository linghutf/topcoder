/**
 * 寻找中位数
 * 1.抽取数组的第一个元素作为中间值，用快速排序的思想进行一次调整，将比中间值小的放在中间值的左边，比中间值大的放在中间值的右边。
 * 2.如果中间值的索引等于数组长度的一半，那么就找到了。
 * 3.如果中位数的索引比数组长度的一半大的话，那么在中间值的索引到数组的结尾这个期间内找第（数组长度的一半-中位数）大的数。
 * 4.否则在数组的开始到中间值的索引这段期间内找第（数组长度的一半大）大的数。递归的调用上面的几步，就可以解决问题了！
 */

#include <iostream>
#include <algorithm>

using namespace std;

int mid(int a[],int len);

/** a[low,hig)
 *  nMax:[0,high-low)
 *
 *  O(n*lgn)
 */
int findNMax(int a[],int low,int high,int nMax);

void testcase()
{
    int data[]={1,2,3,4,2,1,-1,2,1,5,-3,11};
    int len = sizeof(data)/sizeof(data[0]);
    int m = mid(data,len);

    int n1=findNMax(data,0,len,0);
    int n2=findNMax(data,0,len,1);
    int n3=findNMax(data,0,len,2);
    int n4=findNMax(data,0,len,len-1);

    sort(data,data+len);

    if(m==data[len/2])
        cout<<"test mid ok."<<endl;
    if(n1==data[0])
        cout<<"test 1 ok."<<endl;
    if(n2==data[1])
        cout<<"test 2 ok."<<endl;
    if(n3==data[2])
        cout<<"test 3 ok."<<endl;
    if(n4==data[len-1])
        cout<<"test last ok."<<endl;

    cout<<findNMax(data,0,1,0)<<endl;
}
int main(int argc, char *argv[])
{
    testcase();
    return 0;
}

int mid(int a[],int len)
{
    return findNMax(a,0,len,len/2);
}

int findNMax(int a[],int low,int high,int nMax)
{
    if(low>high||nMax<0||nMax>=(high-low))
        throw std::runtime_error("parameter ERROR.");
    int mid = a[low];
    int left = low;
    int right = high-1;

    while(left<right){
        while(left<right && a[right]>=mid) right--;
        a[left] = a[right];
        while(left<right && a[left]<=mid) ++left;
        a[right] = a[left];
    }

    int v = left-low;
    if(v==nMax)
        return a[left];
    else if(v<nMax)
        findNMax(a,left+1,high,nMax-1-v);
    else
        findNMax(a,low,left,nMax);
}


