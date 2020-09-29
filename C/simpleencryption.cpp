#include<stdio.h>
#include <string.h>
int main(){
	int tcase,key;
	char input[1003]={};
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		scanf("%d",&key);getchar();
		scanf("%[^\n]",&input);getchar();
		printf("Case #%d: ",i);
		int len;
		unsigned char baru;
		key=key%26;
		len=strlen(input);
		for (int j=0;j<len;j++){
			baru=input[j];
			if(baru>='A'&&baru<='Z'){
				baru=key+baru;
				if (baru>90){
					baru=baru-90+64;
				}
			//	printf("%d",baru);
				input[j]=baru;
			}
			if (baru>='a'&&baru<='z'){
				baru=key+baru;
	//			if (baru<0){
	//				baru=baru*0+'a'+(key-1);
				if (baru>122){
					baru=baru-122+96;
				}
				input[j]=baru;
			}
			else input[j]=baru;
		}
		printf("%s\n",input);
		
	}
	return 0;
}
