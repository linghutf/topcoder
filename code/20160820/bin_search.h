#ifndef __BINSEARCH__H__
#define __BINSEARCH__H__

class Solution{
    public:
        int search(int A[],int n,int key)
        {
            int low = 0, high = n;
            int mid;
            while(low!=high)
            {
                mid = low + (high - low)/2;
                if(A[mid] == key)
                {
                    return mid;
                }
                if(A[low]<=A[mid])
                {
                    if(A[low] <= key && key < A[mid])
                        high = mid;
                    else
                        low = mid + 1;
                }
                else
                {
                    if(A[mid] < key && key <= A[high-1])
                        low = mid + 1;
                    else
                        high = mid;
                }
            }
            return -1;
        }
};

#endif
