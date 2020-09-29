#include <stdio.h>
int main()
{
	char array[501][501];
	int i,j,tcase,a,b;
	scanf("%d",&tcase);
	for (i=1;i<=tcase;i++){
		scanf("%d %d",&a,&b);
		int row,col,temp=0;
		for (row=2;row<=a+1;row++){
			for (col=0;col<=b;col++){
				if (row==2||row==a+1||col==0||col==b+1){
					array[row][col]='.';
				}
			}
		}
		for (row=1;row<=a;row++){
			scanf("%s",&array[row][1]);
		}
		for (row=2;row<=a+1;row++){
			col=b+1;
			array[row][col]='.';
		}
		for (row=1;row<=a;row++){
			for (col=1;col<=b;col++){
				if (array[row][col]=='|'&&array[row+1][col]=='.')temp++;
				if (array[row][col]=='/'&& array[row+1][col-1]=='.')temp++;
				if (array[row][col]=='\\' && array[row+1][col+1]=='.' )temp++;
			}
		}
		printf("Case #%d: %d\n",i,temp);
	}
	return 0;
}
