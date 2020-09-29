#include <stdio.h>
int main()
{
	int a,b,c,d,n;
	scanf("%d",&n);
	for (b=1;b<=n;b++){
	scanf("%d",&a);
	printf("Case #%d: %d\n",b,a/4-a/100+a/400);
	}
	return 0;
}
