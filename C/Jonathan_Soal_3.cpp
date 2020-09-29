#include<stdio.h>
int main(){
	int tcase,n;
	int jenis[1002];
	char size[1002];
	int temp;
	int hasil;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		scanf("%d",&n);getchar();
		if (n==1)temp++;
		for (int j=0;j<n;j++){
			scanf("%c %d",&size[j],&jenis[j]);getchar();
		}
		int kembar;
		for (int j=0;j<n-1;j++){
			for (int k=j+1;k<n;k++){
				if (size[j]=='a')continue;
				if (size[j]==size[k]&&jenis[j]==jenis[k]){
					temp++;
					kembar++;
					size[j]='a';
					break;
				}
				if (size[j]!=size[k]&&jenis[j]!=jenis[k]){
					temp++;
				}
			}
		}
		int akhir=n=kembar;
		if (temp<akhir){temp++;
		}
		printf("Case #%d: ",i);
		printf("%d\n",temp);
	}
	return 0;
}
