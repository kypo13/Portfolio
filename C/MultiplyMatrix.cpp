#include <stdio.h>
int main()
{
	int r1,r2,c1,c2;
	int a[20][20],b[20][20],hasil[20][20];
	int i,j,k;
	scanf("%d %d",&r1,&c1);
	scanf("%d %d",&r2,&c2);
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<r1;i++){
		for(j=0;j<c2;j++){
			hasil[i][j]=0;
		}
	}
	for(i=0;i<r1;i++){
		for (j=0;j<c2;j++){
			for (k=0;k<c1;k++){
				hasil[i][j]=hasil[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	for (i=0;i<r1;i++){
		for (j=0;j<c2;j++){
			printf(" %d",hasil[i][j]);
			if (j==c2-1)printf("\n\n");
		}
	}
	return 0;
}
