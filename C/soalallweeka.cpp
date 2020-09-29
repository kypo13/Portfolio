#include <stdio.h>
int main()
{
	
	int n,i,j,a;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&a);
		printf("Case #%d:\n",i);
		for (j=a;j>0;j--){
			if (j==5||j==10||j==30||j==60)printf("%d SECONDS TILL NEW YEAR!!\n",j);
			else if (j==a)printf("%d SECONDS TILL NEW YEAR!!\n",j);
			else printf("%d\n",j);
		}
		
	}
	return 0;
}
