/**
 兰博教训提莫之后,然后和提莫讨论起约德尔人,谈起约德尔人,自然少不了一个人,那 就是黑默丁格------约德尔人
 历史上最伟大的科学家. 提莫说,黑默丁格最近在思考一个问题:
 黑默丁格有三个炮台,炮台能攻击到距离它R的敌人
 (两点之间的距离为两点连续的距离,例如(3,0),(0,4)之间的距离是5),
 如果一个炮台能攻击 到敌人,那么就会对敌人造成1×的伤害.黑默丁格将
 三个炮台放在N*M方格中的点上,并且给出敌人 的坐标. 问:那么敌人受到伤
 害会是多大?
 *
 *输入:

 第一行9个整数,R,x1,y1,x2,y2,x3,y3,x0,y0.R代表炮台攻击的最大距离,(x1,y1),(x2,y2),
 (x3,y3)代表三个炮台的坐标.(x0,y0)代表敌人的坐标.

 输出:

 输出一行,这一行代表敌人承受的最大伤害,(如果每个炮台都不能攻击到敌人,输出0×)

 */

#include <iostream>
#include <algorithm>

using namespace std;

#define M 3

struct Point{
    int x,y;
    Point():x(0),y(0){}
    Point(int _x,int _y):x(_x),y(_y){}
    friend istream& operator>>(istream &is,Point &p)
    {
        is>>p.x>>p.y;
        return is;
    }
};

int distance_square(const Point &p,const Point &q)
{
    int xx = p.x-q.x;
    int yy = p.y-q.y;
    return xx*xx+yy*yy;
}

int main(int argc, char *argv[])
{
    unsigned int r;
    Point a[M];
    Point e;

    cin>>r;
    for(int i=0;i<M;++i)
        cin>>a[i];
    cin>>e;

    int val = 0;
    int rs=r*r;
    for(int i=0;i<M;++i)
        if(distance_square(a[i],e)<=rs)
            val++;

    cout<<val<<'x'<<endl;
    return 0;
}
