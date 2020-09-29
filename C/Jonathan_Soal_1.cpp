#include<stdio.h>
int hasil;
int fibo (int awal,int j){
	if (j==1)return awal;
	else if (j==2)return awal;
}
int main(){
	int tcase;
	int j;
	int n,awal;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		scanf("%d %d",&n,&awal);
		for (j=1;j<=n;j++){
			hasil=fibo(awal,j)+hasil;
		}
		hasil=hasil-fibo(awal,j-1);
		printf("Case #%d: %d\n",i,hasil);
	}
	return 0;
}
