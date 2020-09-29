#include <stdio.h>
#include <math.h>
int main()
{
	int n,a,b,c,d,i,j,satu,dua,hasil,hasil1;
	int k=1000000007;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d %d",&satu,&dua);
		if (satu<30){
			hasil=pow(2,satu);	
		}
		if (dua<30){
			hasil1=pow(3,dua);
		}
		//if (sat
		printf("%d",hasil*hasil1);
			
		
	}
	return 0;
}
