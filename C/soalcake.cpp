#include <stdio.h>
int main()
{
	float c,f,a,b,d,e;
	scanf("%f %f",&a,&b);
	d=(int)a/(int)b;
	f=a/b;
	f=f-d;
	e=f*b;
	printf("%.0f %.0f\n",d,e);
	return 0;
}
