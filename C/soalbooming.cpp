#include <stdio.h>
#include <math.h>
int main()
{
	int d,i;
	double c,b,a;
	
	scanf("%lf %lf",&a,&b);
	//d=b-1;
	double r=2.0;
	c=a*(pow(r,b));
	
	printf("%.0lf\n",c);
	return 0;
}
