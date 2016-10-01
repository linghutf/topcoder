/**
 * 矩阵中最近的位置，每次只走一步
 *
 * 可以采用回溯法来实现
 * 将每一处的最少步数记录，针对特殊点进行排序
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Point{
    int x,y;
    int steps;
    bool trap;

    Point():x(-1),y(-1),steps(-1),trap(true){}
    Point(int _x,int _y,bool _trap):x(_x),y(_y),steps(0),trap(_trap){}
};

struct Comp{
    bool operator<(const Point & p,const Point & q)
    {
        if(p.x=q.x)
        {
            return p.y-q.y;
        }
        else
        {
            return p.x-q.x;
        }
    }
};

std::map<Point,int,Comp> g_record;

void dfs(Point & p,int step,int rows,int cols)
{
    if(p.x>=cols||p.y>=rows) return;//越界
    else//记录步数
    {
        if(p.trap)
            g_record[p]=step;
        p.x++;
        dfs(p,step+1,rows,cols);
        p.x--;
        p.y++;
        dfs(p,step+1,rows,cols);
        p.y--;
    }
}

const int MAP_ROWS=1000;
const int MAP_COLS=1000;

int main(int argc, char *argv[])
{
    Point grass_map[MAP_COLS*MAP_ROWS];
    grass_map[0].x=1;
    grass_map[0].y=1;
    grass_map[0].steps = 0;

    int n_trap=0;
    std::cin>>n_trap;

    int asix_x[MAP_COLS];
    int asix_y[MAP_ROWS];

    for(int i = 0;i<n;++i)
    {
        std::cin>>asix_x[i];
    }

    for(int i = 0;i<n;++i)
    {
        std::cin>>asix_y[i];
    }

    int idx = 0;
    for(int i = 0;i<n;++i)
    {
        idx = MAP_COLS*(asix_y[i]-1)+(asix_x[i]-1);
        grass_map[idx].x = asix_x[i];
        grass_map[idx].y = asix_y[i];
        grass_map[idx].trap = true;
    }

    dfs(p,0,MAP_ROWS.MAP_COLS);

    return 0;
}

