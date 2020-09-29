#include <stdio.h>
int main()
{
	int angka[1002],hasil,banyak,total,tcase;
	int flag;
	scanf("%d %d",&banyak,&tcase);
	for (int i=0;i<banyak;i++){
		scanf("%d",&angka[i]);
	}
	for (int i=0;i<tcase;i++){
		scanf("%d",&total);
		printf("Case #%d: ",i+1);
		for (int j=0;j<banyak;j++){
			hasil=0;flag=0;
			for (int k=j;k<banyak;k++){
				hasil=hasil+angka[k];
				if(hasil==total){
					printf("%d %d\n",j,k);
					flag=1;
					break;
				}
			}
			if (flag==1)break;
		}
		if(flag==0)printf("-1\n");
	}
	return 0;
}
