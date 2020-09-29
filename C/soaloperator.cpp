#include<stdio.h>
int main(){
	int t,i,j,n;
	char a,b,c;
//	printf("%d %d %d %d %d",'!','%','&','^','|');
	scanf("%d",&t);
	for(i=1;i<=t;i++){
	 scanf("\n%c %c %c",&a,&b,&c);
	 	
	  for(j=1;j<=3;j++){
	  	if(a>b){
	  		n=a;
	  		a=b;
	  		b=n;
		  }
		 if(b>c){
		 	n=b;
		 	b=c;
		 	c=n;
		 } 
	  }
	  printf("Case #%d: %c %c %c\n",i,a,b,c);	
	}
	
	
	return 0;
}
