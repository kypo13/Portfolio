#include <stdio.h>
int main()
{
	int n,z;
	scanf("%d",&n);
	for(z=1;z<=n;z++){
		int i,y,j,k,a,b=0,c,x,temp,div;
		scanf("%d",&a);
		long long int array2[a]={0};
		long long int array[a]={0};
		printf("Case #%d: \n",z);
		temp=0;
		for (j=1;j<=a;j++){
			for (k=1;k<=a;k++){
				if(j%k==0)temp++;
			}
			if (temp==2) {
			array[b]=j;
			b++;
			}
			temp=0;
		}
		for (j=2;j<=a;j++){
			div = j;
			c=0;
    		while(j>1){
        	if(div%array[c]==0){
            	array2[c]=array2[c]+1;
            	div/=array[c];
            	c=0;
        	}
			else  
                c++;
    		}
    	}
    	for (j=0;j<b;j++){
    		printf("%lld %lld\n",array[j],array2[j]);
		}
		
	}
	
	return 0;
}
