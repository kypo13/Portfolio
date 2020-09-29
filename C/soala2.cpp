#include<stdio.h>
int main()
{
	int i,j,b,n,c,d,x,y,rev,k;
	int a[1000002];
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		scanf("%d",&b);
		for (j=1;j<=b;j++){
			scanf("%d",&a[j]);
		}
		for(j=1;j<=b;j++){
			for (k=j+1;k<=2;k++){
				if (a[j]>a[k]){
					rev=a[j];
					a[k]=a[j];
					a[k]=rev;
				}
			}
		}
		
		
	}
	return 0;
}
