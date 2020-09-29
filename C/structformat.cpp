#include<stdio.h>

struct mahasiswa{
	char nama[100];
	int umur;
}mhs[100];

int main(){
	int byksiswa;
	scanf("%d",&byksiswa);
	
	for (int i=0;i<byksiswa;i++){
		scanf("%s",mhs[i].nama);fflush(stdin);
		scanf("%d",&mhs[i].umur);fflush(stdin);
	}
	return 0;
}
