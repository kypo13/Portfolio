#include <stdio.h>
#include <string.h>
int main()
{
	int a,b,c,d;
	char j[32];
	scanf("%s",j);
	for (a=0;a<30-strlen(j);a++){
		printf("0");
	}	
	
	printf("%s\n",j);
	return 0;
}
