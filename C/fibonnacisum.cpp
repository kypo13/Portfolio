#include<stdio.h>
int hasil;
long long int sumfibo (long long int n){
	if (n<=0)return 0;
	long long int fibo[n+2];
	fibo[0]=0;
	fibo[1]=1;
	hasil=fibo[0]+fibo[1];
	for (int i=2;i<=n;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
		hasil=hasil+fibo[i];
	}
	return hasil;
}
int main(){
	int tcase;
	long long int n,hasil2;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		scanf("%lld",&n);
		hasil2=sumfibo(n)%1000009;
		printf("Case #%d: %lld\n",i,hasil2);
	}
	return 0;
}
