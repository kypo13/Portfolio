#include<stdio.h>
int main()
{
	int i,a,b,c,d,j,k;
	scanf("%d",&a);
	for (i=1;i<=a;i++){
		printf("Case #%d:\n",i);
		scanf("%d %d",&b,&c);
		for (j=1;j<=b;j++){
			for (k=1;k<=c;k++){
				if (j==b||j==1||k==b||k==1){
					printf("*");
				}
				else
				 printf(" ");
			}
			printf("\n");
		}
	
	}
	return 0;
}
