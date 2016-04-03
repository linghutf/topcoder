/**
 * 以(x,y)处为圆心，半径为r的圆，圆心变换到(x1,y1)
 * 每次变换只能以圆边缘做旋转，记录最少变换次数
 *
 * 解题思路:
 * 1.两点之间直线最短，因此圆心沿直线接近
 * 2.圆在以圆周旋转时，圆心可以出现的位置在以2r为半径的圆范围内
 * 3.只要(x,y)和(x1,y1)的距离小于2r,就可以一步变换
 * 4.当距离大于2r,则沿arctan(dy/dx)平移2r个单位(旋转180度)
 * 5.内建函数sin,cos会有精度损失，累积误差会产生影响
 * 6.区分沿x轴或y轴的特殊运动,相应的斜率为
 * x => 0(π),y不惨与后续计算
 * y => ±π/2,x不参与后续计算
 */
#include <iostream>
#include <algorithm>

#include <cmath>

using namespace std;

struct Point{
    int x,y;
    Point():x(0),y(0){}
    Point(int _x,int _y):x(_x),y(_y){}

    friend istream& operator>>(istream& is,Point &p)
    {
        is>>p.x>>p.y;
        return is;
    }

    double distance(const Point &p)
    {
        double d1 = p.x-x;
        double d2 = p.y-y;
        return sqrt(d1*d1+d2*d2);
    }
};

int steps(Point &s,int r,const Point &e)
{
    int step = 1;
    //int range = (r*r)<<2;//(2r)^2
    double seta = 0;
    int d = e.x-s.x;
    bool xflag=false,yflag= false;//判断沿轴线运动,相应的坐标不参与计算

    if(d!=0){
        seta = atan((e.y-s.y)/(e.x-s.x));
        if(seta<1e-7)//seta=0时，表示要向横轴方向移动
            if((e.x-s.x)<0){
                seta = M_PI;//向x轴负半轴移动
                xflag = true;
            }
    }else{
        seta = M_PI/2;
        if((e.y-s.y)<0) seta = -seta; //向y轴负半轴移动
        yflag = true;
    }

    while(s.distance(e)>2*r){
        //沿直线距离接近
        if(!yflag){//保持精度,不是沿y轴平移
            s.x += 2*r*cos(seta);
        }
        if(!xflag){//不是沿x轴平移
            s.y += 2*r*sin(seta);
        }
        step++;
    }
    return step;
}

int main(int argc, char *argv[])
{
    Point s,e;
    int r;
    cin>>r>>s>>e;
    cout<<steps(s,r,e)<<endl;
    return 0;
}
