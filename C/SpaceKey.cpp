#include <stdio.h>
int main()
{
	char str[205];
	int i,j,tcase,len,n,a,b;
	scanf("%d",&tcase);
	for (i=1;i<=tcase;i++){
		scanf("%d",&n);
		scanf("%[^\n]",str);
		printf("Case #%d: ",i);
		for(j=1;j<=n;j++){
			if (str[j]==' '){
				while(str[j]!=' '){
					continue;
				}
			}
			else printf("%c",str[j]);
			
		}
	}
	return 0;
}
