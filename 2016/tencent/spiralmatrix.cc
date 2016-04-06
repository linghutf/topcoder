#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef std::vector<std::vector<int> > Matrix;

void InitMatrix(Matrix &mat,int rows,int cols);
//顺时针打印一圈
void PrintMatrixSpiral(Matrix &mat);
//打印每一圈
void PrintMatrixCircle(Matrix &mat,int start);

//打印数字
void PrintNumber(int num);

int main(int argc, char *argv[])
{
    int rows,cols;
    cin>>rows>>cols;
    Matrix mat;
    InitMatrix(mat,rows,cols);

    PrintMatrixSpiral(mat);
    cout<<endl;

    return 0;
}

void InitMatrix(Matrix &mat,int rows,int cols)
{
    vector<int> v;
    int i,j,c = 0;
    for(i=0;i<rows;++i){
        v.clear();
        for(j=0;j<cols;++j){
            v.push_back(++c);
        }
        mat.push_back(v);
    }
}

void PrintMatrixSpiral(Matrix &mat)
{
    if(mat.empty()||mat.at(0).empty()) return;
    //每一圈左上角的左边
    int start = 0;
    int rows = mat.size();
    int cols = mat.at(0).size();
    while(cols>start*2 && rows>start*2)
    {
        PrintMatrixCircle(mat,start++);
    }
}

//打印每一圈
void PrintMatrixCircle(Matrix &mat,int start)
{
    if(mat.empty()||mat.at(0).empty()) return;
    int rows = mat.size();
    int cols = mat.at(0).size();

    int endX = cols-1-start;//需要打印的列数
    int endY = rows-1-start;//需要打印的行数

    int i,num;
    //从左到右
    for(i=start;i<=endX;++i){
        num = mat.at(start).at(i);//最上面一行
        PrintNumber(num);
    }

    //从上往下
    if(start<endY){
        for(i=start+1;i<=endY;++i){
            num = mat.at(i).at(endY);//最右边一列
            PrintNumber(num);
        }
    }

    //从右往左
    if(start<endX && start<endY){
        for(i=endX-1;i>=start;--i){
            num = mat.at(endY).at(i);//最下面一行endY
            PrintNumber(num);
        }
    }

    //从下往上
    if(start<endX && start<endY-1){
        for(i=endY-1;i>=start+1;--i){
            num = mat.at(i).at(start);//最左边一列
            PrintNumber(num);
        }
    }
}

void PrintNumber(int num)
{
    cout<<setw(4)<<num;
}
