/**
 *
 * 对阵数据文件排序
 *
 */
#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
//#include <chrono>
#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <unordered_map>

#include <climits>
#include <cstdio>
#include <cstdlib>

using namespace std;


void HashSort(FILE *fp,int num,FILE *fout)
{
    if(fp==NULL) return;
    rewind(fp);

    multiset<unsigned int> v;
    unsigned int a;
    for(int i=0;i<num;++i){
        fscanf(fp,"%u",&a);
        v.insert(a);
    }
    for(auto it=v.rbegin();it!=v.rend();++it){
        fprintf(fout,"%12u",*it);
    }
}

void QuickSort(FILE *fp,int num,FILE *fout)
{
    if(fp==NULL||num<=0) return;
    rewind(fp);

    vector<unsigned int> v(num,0);//预先分配位置,提高速度
    unsigned int a;
    for(int i=0;i<num;++i){
        fscanf(fp,"%u",&a);
        v[i]=a;
    }
    std::sort(v.begin(),v.end(),std::greater<unsigned int>());
    for(auto it=v.begin();it!=v.end();++it){
        fprintf(fout,"%12u",*it);
    }
}

void BitSort(FILE *fp,const int num,FILE *fout)
{
    if(fp==NULL||num<=0) return;
    rewind(fp);

    boost::dynamic_bitset<> bitmap(UINT_MAX);
    std::unordered_map<unsigned int,unsigned int> count;

    bitmap.reset();
    unsigned int a;
    for(int i=0;i<num;++i){
        fscanf(fp,"%u",&a);
        if(!bitmap[a])
            bitmap.set(a,true);
        else
            count[a]++;//少一次
    }
    std::unordered_map<unsigned int,unsigned int>::iterator pos;
    for(long i=bitmap.size()-1;i>=0;--i){//避免无符号数不能退出循环
        if(bitmap[i]){//test output;
            fprintf(fout,"%12u",(unsigned int)i);//强制转型
            if((pos = count.find(i))!=count.end()){
                for(unsigned int t=0;t<pos->second;++t){
                    fprintf(fout,"%12u",i);
                }
            }
        }
    }
}

int main(int argc,char *argv[])
{
    if(argc<4){
        printf("usage:%s 1(qsort)|2(hashsort)|3(bitsort) file num.\n",argv[0]);
        return 1;
    }
    int s = atoi(argv[1]);
    int num = atoi(argv[3]);

    FILE *fp = fopen(argv[2],"r");
    if(fp==NULL) return 2;

    FILE *fout = fopen("result","w");
    if(fout==NULL) return 2;

    switch(s){
        case 1:QuickSort(fp,num,fout);break;
        case 2:HashSort(fp,num,fout);break;
        case 3:BitSort(fp,num,fout);break;
        default:printf("error select.\n");
    }
    fclose(fout);

    fclose(fp);
    return 0;
}
