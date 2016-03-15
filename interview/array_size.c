#include <stdio.h>

int GetSize(int *a)
{
	return  sizeof(a);//指针大小
}
int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5};
	int *p=a;//指针大小
	printf("size:%d\n%d\n%d\n",sizeof(a),sizeof(p),GetSize(a));
	return 0;
}