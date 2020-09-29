#include <stdio.h>
#include<string.h>
int main()
{ /*
   int n,i,j;

   printf("Input = ");
   scanf("%d",&n);
   for ( i=1;i<=n;i++){
   	for (j=1;j<=n-i;j++){
   		printf(" ");
	   }
	   for (j=1;j<=i;j++){
	   	printf("* ");
	   }
	   printf("\n");
   }
*/

char nama [30];
scanf("%s",nama);

strrev(nama);
printf("%s",nama);
	
	return 0;
}

