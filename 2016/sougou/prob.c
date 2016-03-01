#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//5%:
int try(int *cnt1,int *cnt2)
{
	srand(time(NULL));
	*cnt1 = 0;
	if(rand()%50>=5){
		(*cnt1)++;
	}
	if(rand()%55>=5){
		(*cnt2)++;
	}
	return 
}
int main(int argc, char const *argv[])
{
	
	return 0;
}