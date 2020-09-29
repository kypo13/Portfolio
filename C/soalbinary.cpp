#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	long long int n,a,b,c,i,j,k,k2,tot;
	long long int n1,n2;
	long long int panjang;
	char array[35];
	scanf("%lld",&n);
	
	for (i=1;i<=n;i++){
		scanf("%s",array);
		panjang=strlen(array);
		
		for(j=panjang-1;j>=0;j--){
			
			
			if (array[j]=='1'){
    			n1=n1+pow(2,c);
   			}
   			else if(array[j]==')'){
    			n1=n1-pow(2,c);
    			j=j-3;
   			}
   			c++;
   		}
   	 	printf("Case #%lld: %lld\n",i,n1);
   	 	n1=0;
   		c=0;
		}	
 



 return 0;
}
