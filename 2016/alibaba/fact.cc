#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<int>& nums,vector<bool>& used,int step,int total,unordered_set<int>& s)
{
    if(step==total){
        int res = 1;
        for(int i=0;i<used.size();++i){
            if(used[i]){
                res*=nums[i];
            }
        }
        //cout<<"res:"<<res<<endl;
        s.insert(res);
    }else{
        for(int i=0;i<nums.size();++i){
            if(!used[i]){
                used[i]=true;
                dfs(nums,used,step+1,total,s);
                used[i]=false;
            }
        }
    }
}

int main()
{
    int n=10;
    vector<bool> used(n,false);
    vector<int> nums={1,2,3,4,5,6,7,8,9};
    unordered_set<int> s;
    for(int i=1;i<=n;++i)
        dfs(nums,used,0,i,s);
    cout<<s.size()<<endl;
    return 0;
}
