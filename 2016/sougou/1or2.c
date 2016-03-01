#include <stdio.h>

int steps(int n)
{
	if(n==1||n==2)
		return n;
	else
		return steps(n-1)+steps(n-2);
}

int main(int argc, char const *argv[])
{
	printf("12:%d,13:%d\n",steps(12),steps(13));
	return 0;
}