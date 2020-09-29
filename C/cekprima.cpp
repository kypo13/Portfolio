#include <stdio.h>
int main()
{
	int i,j,a,b,temp;
	int ch;
	scanf("%d",&a);
	for(i=2;i<=a;i++){
		temp=0;
		for (j=1;j<=a;j++){
			if(i%j==0)temp++;
		}
	}
	if (temp==2)printf("prima");
	else printf("tidak prima");
	return 0;
}
