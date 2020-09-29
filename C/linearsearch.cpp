#include<stdio.h>
#include <string.h>
#define ff fflush(stdin)

int linear(int angka[],int cari){
	for (int i=0;i<5;i++){
		if(cari==angka[i])
		return i;
	}
	return -1;
}
int searchNama(char nama[][100],char cari[]){
	for (int i=0;i<5;i++){
		if(strcmp(cari,nama[i])==0)
			return i;
	}
	return -1;
}

int main(){
	//linear search
	int angka[5]={3,1,2,5,4};
	int flag,cari;
	char nama[100][100]={"Budi","Zandi","Jeje","Cece","Andi"};
	
	char cariNama[100];
	scanf("%s",cariNama);
	flag=searchNama(nama,cariNama);
	printf("Nama %s ketemu di index ke %d",cariNama,flag);
	
//	int cari;
//	int flag;
//	scanf("%d",&cari);ff;
//	flag=linear(angka,cari);
//	printf("Angka %d ketemu di index ke %d",cari,flag);
	
	//if (flag==1)printf("ketemu");
	//else printf("ga ktemu");
	
	
	return 0;
}
