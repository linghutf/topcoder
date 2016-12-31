/**
 *
 * 蛇形数组
 *
 */

#include <stdio.h>
#include <vector>
#include <boost/foreach.hpp>
// 存储数字
void store_num(int num,std::vector<int> * out)
{
    out->push_back(num);
}

// 打印同一圈,从左上角算起
// 至少走1步
// 走2步: 终止行号大于起始行号
// 走3步: 终止行号大于起始行号,终止列号大于起始列号
// 走4步: 至少2行3列,终止行号大于起始行号,终止列号比起始列号至少大2
void print_circle(int ** numbers,int row,int col,int start,std::vector<int> * out)
{
    if(out==NULL) return;
    int x_end = col - 1 - start;//横坐标,j
    int y_end = row - 1 - start;//纵坐标,i
    int i,j;
    // 从左往右,打印第一步
    // 闭区间
    for(j = start;j<=x_end;++j)
    {
        store_num(numbers[start][j],out);
    }
    // 从上往下,打印第二步
    // 左开右闭
    if(y_end>start)
    {
        for(i=start+1;i<=y_end;++i)
        {
            store_num(numbers[i][x_end],out);
        }
    }
    // 从右往左,打印第三步
    // 右开左闭
    if(y_end>start && x_end>start)
    {
        for(j=x_end-1;j>=start;--j)
        {
            store_num(numbers[y_end][j],out);
        }
    }

    // 从下往上,打印第四步
    // 开区间
    if(y_end>start && (x_end-start)>=2)
    {
        for(i=y_end-1;i>start;--i)
        {
            store_num(numbers[i][start],out);
        }
    }
}

// 按照圈数打印
// 判断条件: 左上角的坐标(x,x),x*2<[row|col]
std::vector<int> print_matrix(int ** numbers,int row,int col)
{
    std::vector<int> out;
    if(numbers == NULL||row<=0||col<=0)
        return out;
    //起始位置坐标
    for(int start = 0; start*2<row && start*2<col;++start)
    {
        print_circle(numbers,row,col,start,&out);
    }
    return out;
}

int main(int argc, char *argv[])
{
    int row=4,col=3;
    int ** nums = new int*[row];
    for(int i=0;i<row;++i)
    {
        nums[i] = new int[col];
    }
    // 初始化
    int n = 0;
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            nums[i][j] = ++n;
        }
    }
    printf("---prev---\n");
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<col;++j)
        {
            printf("%3d",nums[i][j]);
        }
        printf("\n");
    }
    printf("---now---\n");
    std::vector<int> out = print_matrix(nums,row,col);
    BOOST_FOREACH(int & n,out)
    {
        printf("%4d",n);
    }
    printf("\n");
    // 释放
    for(int i=0;i<row;++i)
    {
        delete[] nums[i];
    }
    delete[] nums;

    return 0;
}
