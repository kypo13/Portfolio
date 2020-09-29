#include <stdio.h>
int main()
{
	float loop,min,ori;
	float tot,tot2;
	int i,j,k,n,a,b,c;
	float hasil;
	float hasil2;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%f %f %f",&ori,&min,&loop);
		for (j=1;j<=loop;j++){
			b=ori;			
			if(b>min){		
				tot=b+tot;		
			}
			else if(b<=min){
				tot2=min+tot2;
			}
			hasil=tot+tot2;
			ori=ori/2;
		}
		//hasil2=hasil;
		printf("Case #%d: %.3f\n",i,hasil);
	}
	return 0;
}
