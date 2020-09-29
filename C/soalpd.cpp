#include <stdio.h>
int main()
{
	int temp,a,b,c,d;
	scanf("%d",&a);
	for (b=1;b<=a;b++){
		scanf("%d",&temp);
		if (temp==1){
			printf("not easy\n");
			return 0;
		}	
	}printf("easy\n");
	return 0;
}
