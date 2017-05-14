#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> Vec;
Vec g_elements={1,2,3,1};
std::vector<bool> g_states;

void part(Vec& v, std::vector<bool> & states, int depth)
{
    if(depth==states.size()){
        for(auto it=v.begin();it!=v.end();++it){
            printf("%4d",*it);
        }
        printf("\n");
    }else{
        for(int i=0;i<states.size();++i)
        {
            if(!states[i]){
                states[i]=!states[i];
                v[depth] = g_elements[i];
                part(v,states,depth+1);
                states[i]=!states[i];
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int sz = g_elements.size();
    //std::unique();
    std::vector<bool> states(sz,false);
    Vec v(sz,0);
    part(v,states,0);
    return 0;
}
