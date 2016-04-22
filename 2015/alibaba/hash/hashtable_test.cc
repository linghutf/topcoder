#include <iostream>

#include "hashtable.hh"

using namespace std;

void testcase()
{
    KeyHash<int> hash;
    int i=10;
    int j=12;
    cout<<"int test:\n"<<hash(i)<<endl;
    cout<<hash(j)<<endl;

    double f = 0.9;
    double g = 0.9;
    KeyHash<int> hashf;
    cout<<"double test:\n"<<hashf(f)<<"\n"<<hashf(g)<<endl;
}

int main()
{
    //testcase();

    HashTable<int,int> table;
    table.put(10,1);

    int v = 0;
    for(int i=0;i<=10;++i){
        //if(table.get(i,v))
            cout<<i<<":"<<table[i]<<endl;
    }

    if(table.find(0)==nullptr){
        cout<<"failed.\n";
    }

    if(table.find(12)!=nullptr){
        cout<<"failed.\n";
    }

    if(table.count(1)>0){
        cout<<"test count ok!\n";
    }

    table.remove(2);
    if(table.count(2)>0){
        cout<<"test remove failed.\n";
    }

    table.remove(10);
    cout<<"10:"<<table[10]<<endl;

    return 0;
}
