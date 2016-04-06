/**
 * 倒三角型矩阵
 *
 * 3:   1 3 6
 *      2 5
 *      4
 *
 * 4:   1 3 6 10
 *      2 5 9
 *      4 8
 *      7
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    int n=5;
    char tmp[100];
    int x=1,y=2,z=1;
    int a;
    cin>>tmp;
    //while(tmp[0]!='#'){
    n=atoi(tmp);
    for(int i=1;i<=n;++i){
        a=x;
        for(int j=1;j<=n-i+1;++j){
            cout<<a;
            if(j<n-i+1) cout<<" ";
            a+=y++;
        }
        cout<<endl;
        x+=z++;
        y=z+1;
    }
 //       x=1,y=2,z=1;
        cin>>tmp;
  //  }
    return 0;
}
