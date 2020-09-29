#include <stdio.h>
int main()
{
	int n,a,b;
	float i,j,k,x,y,z;
	float hasilx,hasily;
	scanf("%d",&n);
	for (a=1;a<=n;a++){
		scanf("%f %f %f\n",&i,&j,&k);
		scanf("%f %f %f",&x,&y,&z);
		hasilx= ((j*z)-(y*k))/(i*y)-(x*j);
		hasily= ((x*k)-(i*z))/(i*y)-(x*j);
		printf("Case #%d:\n",a);
		printf("x = %.4f\n",hasilx);
		printf("y = %.4f\n",hasily);
		
	}
	return 0;
}
