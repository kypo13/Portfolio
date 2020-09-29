#include <stdio.h>
int main()
{
	int n,a,i,j,k,l;
	scanf("%d",&n);fflush(stdin);
	a=n;
	for (i=0;i<n;i++){
		for (j=a-1;j>0;j--){
			printf(" ");
		}
		for (k=0;k<=i;k++){
			printf("#");
		}
		for (l=0;l<i;l++){
			printf("#");
		}
		printf("\n");
		a--;
	}
	return 0;
}
