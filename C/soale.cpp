#include <stdio.h>
int main()
{
	int i,j,k,a,b,c,n;
	int array[1002];
	scnaf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		x=1;
		for (j=1;j<=a;j++){
			temp=0;
			for (k=1;k<=a;k++){
				if(j%k==0)temp++;
			}
		
		if (temp==2) array[j]=array[j]+x;
		else int div = 2;
    
    		while(number!=0){
        	if(number%div!=0)
            	div = div + 1;
        	else {
            	number = number / div;
            	printf("%d ",div);
            	if(number==1)
                break;
        		}
    		}
		}
	}
	}
	return 0;
}
