#include<stdio.h>
int main()
{   
    int t,buka,tutup,n;
    int count[101];
    
    scanf("%d",&t);
    
    for ( int i = 1; i <= t; i++)
    {
    	scanf("%d",&n);
    	
    	//dibuka semua
    	for ( int j = 1; j <= 100; j++)
    	{
    		count[j] = 1;
		}
		
		for ( int j = 2; j <= n; j++)
		{
			for ( int k = 2; k <= n; k++)
			{
				 if ( j % k == 0 && count[j] == 1)
				 {
				 	count[j] = 0;
				 }
				 else if ( j % k == 0 && count[j] == 0)
				 {
				 	count[j] = 1;
				 }
			}
		}
		buka = 0;
		for ( int j = 1; j <= n; j++)
		{
			if ( count[j] == 1)
			{
				buka+=1;
			}
		}
		
		printf("%d",buka);
	}
	
	
	
	return 0;
}
