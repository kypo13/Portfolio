#include<stdio.h>
int main(){
	int t,sisa,jumlah;
	long long n,c;
	
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%lli",&n);
		sisa=0;
		c=n;
		printf("Case #%d: ",i+1);
		printf("%lli",n);
		
		do{
			while(c!=0){
			sisa=c%10;
			jumlah=jumlah+sisa;
			c=c/10;
			}
			c=jumlah;
			if(c!=n)printf(" %lli",c);jumlah=0;
		}while(c>=10);
		printf("\n");
	}
	return 0;
}
