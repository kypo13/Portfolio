#include<stdio.h>
#include<string.h>
int main(){
	char word[25];
	char reverse[25];
	int len;
	scanf("%s",word);
	len=0;
	while(word[len]!=NULL){
		len++;
	}
	strcpy(reverse,word);
	int i=0;
	int j=len-1;
	char temp;
	while(i<j){
		temp=reverse[i];
		reverse[i]=reverse[j];
		reverse[j]=temp;
		i++;
		j--;
	}
	if (strcmp(reverse,word)==0)printf("its a palindrome");
	else printf("Its not");
	
	return 0;
}
