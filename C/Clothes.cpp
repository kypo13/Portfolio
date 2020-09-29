#include<stdio.h>
int main()
{
	int tcase,banyak;
	int color[100002]={};
	char size[100002]={};
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		scanf("%d",&banyak);getchar();
		for (int j=0;j<banyak;j++){	
			scanf("%c %d",&size[j],&color[j]);getchar();
		}
		int count=0;
		for (int k=0;k<banyak-1;k++){
			for (int l=k+1;l<banyak;l++){
				if (size[l]=='a'){
					continue;
				}
				if (size[k]==size[l]&&color[k]==color[l]){
					size[l]='a';
					count=count+10;
					break;
				}				
			}
						
		}
		printf("Case #%d: %d\n",i,count);

		}
	
	return 0;
}
