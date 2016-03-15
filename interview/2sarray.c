#include <stdio.h>
#include <stdlib.h>

void search(int key,int (*a)[3],int rows,int cols,int *x,int *y)
{
	*x=*y=-1;
	if(a==NULL||rows<=0||cols<=0)
		return;
	int i=0,j=cols-1,val;
	while(i<rows&&j>=0){
		val = a[i][j];//*(*(a+i)+j);
		if(val==key){
			*x=i;
			*y=j;
			break;
		}else if(val<key){
			i++;
		}else{
			j--;
		}
	}
}

int main(int argc, char const *argv[])
{
	int key = atoi(argv[1]);

	int a[][3]={
		1,2,3,4,5,6,7,8,9
	};
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			printf("%4d",*(*(a+i)+j));
		}
		printf("\n");
	}
	int pos_x,pos_y;
	search(key,a,3,3,&pos_x,&pos_y);
	printf("%d,%d\n",pos_x,pos_y);
	return 0;
}