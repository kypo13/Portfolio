#include <stdio.h>
int main()
{
	int i,j,a,b,c;
	for(i=1;i<=3;i++){
		scanf("%d",&a);
		if (a==1){
			printf("I love fruit\n");
		}
		else if(a==2){
			printf("I love vegetable\n");
		}
		else if (a==3){
			printf("No comment\n");
		}
	}
	return 0;
}
