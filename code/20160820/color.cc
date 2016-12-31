/**
 * 五种颜色的珠子一串，找到包含五种颜色的最短的区间
 */
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

void get_sub_all(int data[],int len,int color,int ** least)
{
    *least = new int[len];
    if(*least==NULL) return;

    int * next = new int[len];
    if(next==NULL) return;

    int * color_count = new int[color];
    if(color_count==NULL) return;

    int * color_tmp = new int[color];
    if(color_tmp==NULL) return;
    for(int i=0;i<len;++i)
    {
        next[i]=-1;
    }

    for(int i=0;i<color;++i)
    {
        color_tmp[i]=-1;
    }

    for(int i=len-1;i>=0;--i)
    {
        next[i] = color_tmp[data[i]];
        color_tmp[data[i]] = i;
    }

    int has_color = 0;//已经发现的颜色总数
    int begin_tag = 0,end_tag = 0;
    // 找到第一个包含所有颜色的结束点
    while(end_tag<len)
    {
        if(color_count[data[end_tag]]==0)
        {
            ++has_color;
            ++color_count[data[end_tag]];
        }
        if(has_color==color) break;
        ++end_tag;
    }

    // 结束点逐步后移，然后找到以end_tag为结束点的最短区间
    while(end_tag<len)
    {
        if(next[begin_tag]>=0 && next[begin_tag]<=end_tag)
        {
            ++begin_tag;
            continue;
        }

        (*least)[end_tag] = end_tag-begin_tag+1;
        ++end_tag;
    }
    delete color_tmp;
    delete color_count;
    delete next;
}

int main(int argc, char *argv[])
{
    int data[]={1,2,3,4,4,5,4,2,3,1,2,3};
    int len = sizeof(data)/sizeof(data[0]);
    int * least;
    int color = 5;
    get_sub_all(data,len,color,&least);

    for(int i=0;i<color;++i)
    {
        std::cout<<std::setw(4)<<least[i];
    }
    std::cout<<std::endl;

    delete least;

    return 0;
}
