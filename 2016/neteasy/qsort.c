#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void mid(int *a,int *b,int *c)
{
    if(*a<*b){
        if(*a<*c){
            if(*b<*c){
                swap(a,b);
            }else{
                swap(a,c);
            }
        }
    }else{
        if(*b<*c){
            if(*a>*c){
                swap(a,b);
            }
        }else{
            swap(a,b);
        }
    }
    /*if(a<b){
        return a<c? (b<c?b:c):a;
    }else{
        return a<c? b:(b<c?c:b);
    }*/
}

int partition(int a[],int low,int high)
{
    mid(a+low,a+(high+low)/2,a+high);
    int m = a[low];
    int i=low,j=high+1;
    while(i<j){
        while(a[++i]<m){
            if(i==high) break;
        }
        while(a[--j]>m){
            if(j==low) break;
        }
        if(i>=j) break;
        swap(a+i,a+j);
    }
    swap(a+low,a+j);
    return j;
}

void quicksort(int a[],int low,int high)
{
    if(low>=high) return;
    int index = partition(a,low,high);
    quicksort(a,low,index-1);
    quicksort(a,index+1,high);
}

void Qsort(int a[],int len)
{
    quicksort(a,0,len-1);
}

void print(int a[],int len)
{
    for(int i=0;i<len;++i)
        printf("%3d",a[i]);
    printf("\n");
}

void testcase()
{
    int a[]={0};
    Qsort(a,1);
    print(a,1);

    int a1[]={-3,4,1,7};
    int len = sizeof(a1)/sizeof(a1[0]);
    Qsort(a1,len);
    print(a1,len);

    int a2[]={-1,-2,-3};
    int len2 = sizeof(a2)/sizeof(a2[0]);
    Qsort(a2,len2);
    print(a2,len2);

}

int main(int argc, char *argv[])
{
    testcase();
    return 0;
}
