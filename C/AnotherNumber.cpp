#include<stdio.h>
int main()
{
	long long int tcase,a,b,c,d;
	long long int temp;
	long long int hasil;
	scanf("%lld",&tcase);
	for (int i=1;i<=tcase;i++){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		temp=0;
		for (int j=0;j<=100000;j++){
			hasil=((a*j)+b)%d;
			if(hasil==c){
				temp++;
				break;
			}	
		}
		if (temp==1){
			printf("Case #%lld: YES\n",i);
		}
		else printf("Case #%lld: NO\n",i);
	}
	return 0;
}
