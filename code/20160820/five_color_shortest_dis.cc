#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <boost/unordered_map.hpp>

int shortest_full_color(int a[],int len,int m,std::pair<int,int> & out)
{
    boost::unordered_map<int,int> colors;
    int color_num = m;//记录颜色总数
    int ss = 0,kk = 0;//2个移动指针
    int min = len;
    out.first = 0;
    out.second = len-1;

    while(true)
    {
        while(color_num>0 && ss<len)//一直找到颜色都有为止
        {
            if(colors[a[ss]]==0)// 这个颜色还未存在，找到一个新颜色
            {
                --color_num;
            }
            // 该颜色次数加一
            colors[a[ss]]++;
            ss++;
        }

        while(true)
        {
            // 使用该位置试探
            colors[a[kk]]--;
            if(colors[a[kk]]==0)//该颜色就这一种，获取整个长度
            {
                break;
            }
            kk++;//颜色不止一种，向后移动，可以不要当前位置
        }

        if(min>ss-kk)
        {
            min = ss-kk;
            out.first = kk;
            out.second = ss;
        }

        kk++;//当前kk的颜色减去，从下个位置开始，查找减去的颜色
        color_num++;//减去的颜色，要重新查找
        if(ss>=len)
        {
            return min;
        }
    }
}

int main(int argc, char *argv[])
{
    int a[]={1,2,3,3,2,5,2,2,1,3,3,4,5,4,3};
    int len = sizeof(a)/sizeof(a[0]);
    int ans;
    int colors = 5;
    std::pair<int,int> res;
    ans = shortest_full_color(a,len,colors,res);
    std::cout<<"len:"<<ans<<std::endl;
    for(int i=res.first;i<res.second;++i)
    {
        std::cout<<a[i]<<"\t";
    }
    std::cout<<"\n";

    return 0;
}
