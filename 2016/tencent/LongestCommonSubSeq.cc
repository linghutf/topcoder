/**
 * 求最长回文序列(不是回文子串)
 *
 * 原意:字符串S中含有不是回文的字符，需要删除它们来求得最长回文串
 *
 * 等价:将S逆序变成T,然后求最长公共序列
 * 解法:动态规划
 * 时间复杂度: O(mn)=O(n^2)
 * 空间复杂度: O(mn)=O(n^2),矩阵
 *
 *
 */

#include <iostream>
#include <algorithm>
#include <string>

#include <vector>
#include <iomanip>

using namespace std;

typedef std::vector<std::vector<int> > Matrix;

void InitMatrix(Matrix &mat,int rows,int cols)
{
    //std::vector<int> v(0,cols);//不能这么初始化
    std::vector<int> v(0);
    v.resize(cols);
    for(int i=0;i<rows;++i){
        mat.push_back(v);
    }
}

void PrintMat(const Matrix &mat)
{
    int rows = mat.size();
    int cols = mat[0].size();

    for(u=0;u<rows;++u)
    {
        for(v=0;v<cols;++v){
            cout<<setw(3)<<mat[u][v];
        }
        cout<<endl;
    }
}

void SubSequence(const std::string &s,Matrix &flags,int rows,int cols,std::string& result)
{
    int i=rows-1,j=cols-1;
    while(i>=0 && j>=0){
        switch(flags[i][j]){
        case 2://left-up
            result.push_back(s[j-1]);
            --i;--j;break;
        case 1://up
            --i;break;
        case 0://left
            --j;
        }
    }
}

int LongestCommonSubSequence(const std::string &s,const std::string &t,std::string &result)
{

    //申请矩阵空间
    int m = t.length();//row
    int n = s.length();//col

    //计算矩阵
    Matrix mat;
    InitMatrix(mat,m+1,n+1);
    //推导路径矩阵
    //2表示left-up(左上)
    //1表示up(上)
    //0表示left(左)
    Matrix flags;
    InitMatrix(flags,m+1,n+1);
    //计算
    int i,j;
    for(i=1;i<=m;++i){
        for(j=1;j<=n;++j){
            //相等
            if(s.at(j-1)==t.at(i-1)){
                mat[i][j]=mat[i-1][j-1]+1;//多一个匹配
                flags[i][j]=2;//left-up
                //result.push_back(t.at(i-1));
            }else{
                //比较矩阵左边和上方的值，选取max
                //mat[i][j]=std::max(mat[i-1][j],mat[i][j-1]);
                if(mat[i-1][j]>=mat[i][j-1]){
                    mat[i][j]=mat[i-1][j];
                    flags[i][j]=1;//up
                }else{
                    mat[i][j]=mat[i][j-1];
                    flags[i][j]=0;//left
                }
            }
        }
    }
    //保存序列
    SubSequence(s,flags,m+1,n+1,result);

    /*debug info.*/
    PrintMat(mat);
    return mat[m][n];
}

void testcase()
{
    string s;
    cin>>s;
    string t;
    std::reverse_copy(s.begin(),s.end(),std::back_inserter(t));
    cout<<s<<endl<<t<<endl;

    string r;
    int len = LongestCommonSubSequence(s,t,r);
    cout<<r<<",len="<<len<<endl;
}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
