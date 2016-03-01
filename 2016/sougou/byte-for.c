#include <stdio.h>

int main(int argc, char const *argv[])
{
	unsigned char i=7;
	int j=0;
	for(;i>0;i-=3){
		j++;
	}
	printf("%d\n",j);
	return 0;
}