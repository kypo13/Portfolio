#include <stdio.h>
int main()
{

	char a[10],b[10],c[10];
	char d[8],e[8],f[8];


	scanf ("%[A-z]%[0-9]%[A-z]%[0-9]%[A-z]%[0-9]",a,d,b,e,c,f);

	
	printf("%-10s %s\n",a,d);
	printf("%-10s %s\n",b,e);
	printf("%-10s %s\n",c,f);
	return 0;
}
