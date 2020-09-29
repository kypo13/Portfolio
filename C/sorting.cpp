#include<stdio.h>
#include <string.h>
//void swap(char &a,char &b){
//	char temp;
//	strcpy(temp,a);
//	strcpy(a,b);
//	strcpy(b,temp);
//}
void sort(char nama[][100]){
	for (int i=0;i<5;i++){
		for (int j=0;j<4;j++){
			if (strcmp(nama[j],nama[j+1])<0){
				char temp[100];
				strcpy(temp,nama[j]);
				strcpy(nama[j],nama[j+1]);
				strcpy(nama[j+1],temp);
			}
		}
	}
}

int main(){
	//sort
	char nama[100][100]={"Budi","Zandi","Jeje","Cece","Andi"};
	int angka[5]={3,1,2,5,4};
	sort(nama);
	
	for (int i=0;i<5;i++){
		printf("%s\n ",nama[i]);
	}
	
	return 0;
}
