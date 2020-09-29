#include <stdio.h>

int main (){
	int t,n,a,flag=0;
	scanf("%d",&n);
	for (a=1;a<=n;a++){
	printf("Case #%d:\n",a);
	scanf("%d" , &t);
	
	for(int i = 1 ; i <= t ; i++){
		flag = 0;
		for(int j = 1; j <= i ; j++){
			if(i % j == 0){
				flag++;
			}
		}
		if (flag == 2)printf("I will become a good boy.\n");
		
	}
}
	return 0;
}
