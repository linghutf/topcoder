#include <string.h>
#include <iostream>
#include <iomanip>
#include <boost/foreach.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

void * mymemcpy(void * dst,const void * src,size_t n)
{
    if(dst==NULL||src==NULL)
    {
        return NULL;
    }
    else if(n==0||dst==src)
    {
        return dst;
    }

    char * p = (char*)dst;
    char * q = (char*)src;
    size_t cnt = 0;//标准中大小不做检查
    while(cnt!=n)
    {
        *p++=*q++;
        cnt++;
    }
    return dst;
}

// 反向拷贝
void *mymemmove(void * dst,const void * src,size_t n)
{
    if(dst==NULL||src==NULL)
    {
        return NULL;
    }
    else if(n==0||dst==src)
    {
        return dst;
    }

    char * p = (char*)dst+n-1;
    char * q = (char*)src+n-1;
    while(n!=0)
    {
        *p--=*q--;
        n--;
    }
    return dst;
}

char * mystrcpy(char * dst,const char * src)
{
    if(dst==NULL||src==NULL)
        return NULL;
    if(dst==src)
        return dst;
    char * p = (char*)src;
    char * q = dst;
    while((*q++=*p++)!='\0');
    return dst;
}

void kmp(const char * src,int next[])
{
    int i = 0,j = -1;
    next[i]=j;
    while(i<strlen(src))
    {
        // 回到起点
        // 或者是该位置匹配
        if(j==-1||src[i]==src[j])
        {
            ++j;
            ++i;//下一个位置
            if(src[i]==src[j])//记录，直接回退之前的位置
            {
                next[i]=next[j];
            }
            else//记录，后退一位
            {
                next[i]=++j;
            }
        }
        else//回退操作
        {
            j=next[j];
        }
    }
}

int mystrstr(const char * sub, const char *src)
{
    if(sub==NULL||src==NULL)
    {
        return -1;
    }

    size_t len = strlen(src);
    size_t sublen = strlen(sub);
    if(len==0||sublen==0)
    {
        return 0;
    }

    int* next = new int[len];
    kmp(src,next);

    int i=0,k=-1;
    int pos = -1;
    bool found = false;
    while(i<len)
    {
        if(k==-1||src[i]==sub[k])
        {
            ++k;
            ++i;
            if(k==sublen)
            {
                found = true;
                break;
            }
        }
        else
        {
            // 回退
            k=next[k];
        }
    }
    // 找到位置
    if(found)
    {
        pos = i-k;
    }
    delete next;

    return pos;
}
/*
template<typename T>
void test_my_func(boost::function<T(T, const T, size_t)> & func,T src,T dst,size_t n)
{
    func(dst,src,n);
}
*/
typedef  void* (*FuncPtr)(void *,const void *,size_t);

// 测试strstr
void test_strstr()
{
    char str[]="I love you.";
    std::string sub;
    std::cin>>sub;
    int cnt = 0;
    for(int i=0;i<strlen(str);++i)
    {
        std::cout<<std::setw(4)<<i;
    }
    std::cout<<std::endl;
    for(int i=0;i<strlen(str);++i)
    {
        std::cout<<std::setw(4)<<str[i];
    }
    std::cout<<std::endl;
    std::cout<<mystrstr(sub.c_str(),str)<<std::endl;
}

int main(int argc, char *argv[])
{
    int a[]={1,3,-2,12,9};
    int arr[10]={0};
    mymemcpy(arr,a,sizeof(a));

    BOOST_FOREACH(int & n,arr)
    {
        std::cout<<n<<'\t';
    }
    std::cout<<std::endl;

    // 有交叉情况
    char str[32]="I love you.";
    if(argc!=2)
    {
        std::cout<<"usage:"<<argv[0]<<std::endl;
        return 1;
    }

    int c = atoi(argv[1]);
    if(c<0 || c>3)
    {
        std::cout<<"choice ERROR!\n";
        return 2;
    }

    const size_t NUM = 16;
    FuncPtr func[NUM];
    func[0] = mymemcpy;
    func[1] = memcpy;
    func[2] = mymemmove;
    func[3] = memmove;

    func[c](str+4,str,strlen(str));
    std::cout<<str<<std::endl;
    /*
    switch(c)
    {
        case 0:(mymemcpy,str+4,str,strlen(str));
               break;
        case 1:(mymemcpy,str+4,str,strlen(str));
               break;
        default:
               std::cout<<"choice ERROR!\n";
    }
    */

    // 越界情况
    memcpy(arr,a,100);

    //test_my_func<void*>(mymemcpy,(void*)(str+4),(void*)str,32);

    // KMP测试
    std::cout<<"kmp测试:"<<std::endl;
    test_strstr();

    return 0;
}
