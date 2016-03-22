#include <cstdio>
using namespace std;

const int row = 8,col = 8;
int a[row];
static int num = 0;

bool isdiag_line(int rstep,int pos)
{
    int i;
    for(i=0;i<rstep;++i){//检查之前的状态
        if(i+a[i] == pos+rstep) return true;//45°方向斜对角线
        if(i-a[i] == rstep-pos) return true;//逆方向对角线
        if(pos == a[i]) return true;//同一列
    }
    return false;
}
//按行选择位置
void backtrack(int a[],int rstep)
{
    int i,j;
    if(rstep<row){
        //从第一列选择
        for(j=0;j<col;++j){
            if(!isdiag_line(rstep,j)){
                a[rstep] = j;
                backtrack(a,rstep+1);
            }
        }
    }else{
        num++;
        printf("\n--------\n");
        for(i=0;i<row;++i){
            for(j=0;j<col;++j){
                if(j!=a[i]) printf("%2c",'x');
                else printf("%2d",1);
            }
            printf("\n");
        }
    }
}

int main(int argc, char *argv[])
{
    backtrack(a,0);
    printf("total:%d\n",num);
    return 0;
}
