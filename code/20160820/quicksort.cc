#include <iostream>
#include <algorithm>
#include <boost/foreach.hpp>

template<typename T,typename Pred>
class Solution{
    private:
        static Pred pred;
    public:
        void myqsort(T * a, int len)
        {
            if(a==NULL||len<=0) return;
            quicksort(a,0,len-1);
        }

    private:
        void quicksort(T * a , int low, int high)
        {
            if(low<high)
            {
                int p = partition(a,low,high);
                quicksort(a,low,p-1);
                quicksort(a,p+1,high);
            }
        }

        int partition(T * a,int low,int high)
        {
            Pred cmp;
            T privot = a[low];
            int i = low+1;
            int j = high;
            while(i<=j)
            {
                while(cmp(a[i],privot)) ++i;
                while(!cmp(a[j],privot)) --j;
                if(i>j) break;
                std::swap(a[i++],a[j--]);
            }
            std::swap(a[j],a[low]);
            return j;
        }
};

int main(int argc, char *argv[])
{
    int a[]={-3,11,4,5,1,-7,5,-3};
    Solution<int,std::less<int> > s;
    s.myqsort(a,sizeof(a)/sizeof(a[0]));

    BOOST_FOREACH(int & n,a)
    {
        std::cout<<n<<'\t';
    }
    std::cout<<'\n';
    return 0;
}
