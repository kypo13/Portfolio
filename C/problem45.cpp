#include <stdio.h>
int main()
{
	int n;
	int matrix[102][102];
	int max1[255];int max[255];
	int a,j,k;
	
	scanf("%d", &n );
	for (int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		for (j=0;j<a;j++){
			for (k=0;k<a;k++){
				scanf("%d",&matrix[j][k]);
		}
	}
		for (j=0;j<a;j++){
			matrix[j][k]=-128;
			max[j]=matrix[j][k];
			for (k=0;k<a;k++){
				if (matrix[j][k]>max[j]){
					max[j]=matrix[j][k];
				}
			}
		}
		for (j=0;j<a;j++){
			matrix[k][j]=-128;
			max1[j]=matrix[k][j];
			for (k=0;k<a;k++){
				if (matrix[k][j]>max1[j])
				max1[j]=matrix[k][j];
			}
		}	
		printf("Case #%d:\n",i);
		printf("Row :");
		for (j=0;j<a;j++) printf(" %d",max[j]);
		
		printf("\nCol :");
		for (k=0;k<a;k++)printf(" %d",max1[k]);
		}
		printf("\n");
	

	return 0;
}
