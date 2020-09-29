#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

int n,i;
	 
  scanf("%ld",&n);
  for (i=1;i<=n;i++){
  	while (n--){
	  long int a,b,c,d,temp,temp2;
	  long int reverse1,reverse=0;
  
   scanf("%ld",&a);
   printf("Case #%ld: ",i++);
   
	temp=a;
	for (reverse1=0;temp>0;temp=temp/10)
   {
      reverse1 = reverse1 * 10;
      reverse1 = reverse1 + temp%10;
      
   }
 // printf(" %ld",reverse1);
   c=a+reverse1;
  // printf(" %ld",c);
   temp2=c;
   for (reverse=0;temp2>0;temp2=temp2/10){
   	reverse= reverse*10;
   	reverse=reverse+temp2%10;
   	
   }
   
    printf("%ld %ld %ld %ld\n",a,reverse1,c,reverse);
	}
   
}
   return 0;
}
