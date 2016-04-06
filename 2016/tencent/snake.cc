/**
 * 打印蛇形数组
 * n=3
 *  1  2  3    00 01 02
 *  8  9  4    10 11 12
 *  7  6  5    20 21 22
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

typedef std::vector<std::vector<int> > Matrix;

void Init(Matrix &a,int n)
{
    for(int i=0;i<n;++i){
        a.push_back(std::vector<int>(0,n));
    }
}

void Snake(Matrix &a)
{
    const int m = a.size();
    const int n = a.at(0).size();
    bool flag[m][n];

    int coord[2]={0};
    int screw[m][n];

    int i=0,j=0;
    int d=1;
    int gap = n-1;
    while(i<n&&j<n){
        while((i+j)<=gap && i<=j){
            a[i][j]=d++;
            j++;
        }
        while((i+j)>gap && i<=j){
            a[i][j]=d++;
            i++;
        }
        while((i+j)>=gap && i>j){
            a[i][j]=d++;
            j--;
        }
        while((i+j)<gap && i>=j){
            a[i][j]=d++;
            i--;
        }
    }
}

void Print(Matrix &a,int n)
{
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<n;++j){
            std::cout<<setw(4)<<a[i][j];
        }
        std::cout<<std::endl;
    }
}

int main(int argc, char *argv[])
{
    int n;
    cin>>n;

    Matrix a;

    Init(a,n);
    Snake(a,n);
    Print(a,n);
    return 0;
}
