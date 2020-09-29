#include<string.h>
#include <stdio.h>
int main()
{
	int count,tcase,i,j;
	char input[1000000003]={};
	scanf("%d",&tcase);
	getchar();
	for (i=1;i<=tcase;i++){
		scanf("%s",input);
		getchar();
		count=0;
		for (j=0;j<strlen(input);j++){
			if (input[j]=='7'||input[j]=='8')
			count=1;
		}
		if (count==1)printf("Case #%d: YES\n",i);
		else printf("Case #%d: NO\n",i);
		count=0;
	}
	return 0;
}
