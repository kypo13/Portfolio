#include<stdio.h>
#include<string.h>
int main(){
	int tcase;
	char kata[100],cari[100];
	char *temp;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		scanf("%s %s",kata,cari);
		strrev(kata);
		strrev(cari);
		printf("Case #%d: ",i);
		printf("%s\n",strrev(strstr(kata,cari)));
		}

	
	return 0;
}
