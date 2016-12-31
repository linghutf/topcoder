#ifndef __SORT__HH__
#define __SORT__HH__

#include <algorithm>

namespace sort
{
    class ISort
    {
        public:
            virtual bool operator<(ISort & a)
            {
                return true;
            }
    };

    class Sort
    {
        public:
            static void select_sort(ISort * arr,int len)
            {
                int i;
                ISort * p = NULL;
                for(i=0;i<len;++i)
                {
                    p = std::min_element(arr+i,arr+len);
                    if(p!=NULL)
                    {
                        if(p!=arr+i)
                        {
                            std::swap(*p,arr[i]);
                        }
                    }
                    p = NULL;

                }
            }
    };

}

#endif
