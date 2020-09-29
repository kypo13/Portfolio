#include <stdio.h>
int main()
{
	int i,j,k,tcase,n,a,b,input;
	int batas=100000000;
	int count=0;
	for (i=1;i<=batas;i++){
		if (i%7==0&&i%8==0){
			count=1;
		}
	}
	scanf("%d",&tcase);
	for (j=1;j<=tcase;j++){
		scanf("%d",&input);
		for (k=1;k<=input;k++){
			if (k%7==0||k%8==0){
				count=1;
			}			
		}
		if (count==1)printf("Case #%d: YES\n");
		else printf("Case #%d: NO\n");
		count=0;

	}
	return 0;
}
