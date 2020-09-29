#include <stdio.h>
#include <math.h>
int main()
{
	double n,k;
	scanf("%lf %lf",&n,&k);
	
	n= n*(pow(2,k));
	printf("%0.0f\n",n);
	return 0;
}
