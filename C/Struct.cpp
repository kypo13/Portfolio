#include<stdio.h>
#include<string.h>
int count;
//tipedata Nama_Variabel{};
struct Mahasiswa{
	char nama[100];
	int umur;
	char univ[100];
}mhs[100];

void bacafile(){//loadgame
	count=0;
	FILE *read=fopen("Mahasiswa.txt","r");
	while(!feof(read)){
		fscanf(read,"%[^#]#%d\n",mhs[count].nama,&mhs[count].umur);
		count++;
	}
	fclose(read);
}
void print(){
	for (int i=0;i<count;i++){
		printf("%s,%d\n",mhs[i].nama,mhs[i].umur);
	}
}
void tulisfile(){
	FILE *tulis=fopen("Mahasiswa.txt","w");
	for(int j=0;j<count;j++){
		fprintf(tulis,"%s#%d\n",mhs[j].nama,mhs[j].umur);
		
	}
	fclose(tulis);
}
int main(){
//	bacafile();
//	print();
	int n;
	scanf("%d",&n);fflush(stdin);
	for(int i=0;i<n;i++){
		printf("Masukkan nama,umur");
		scanf("%[^\n]",mhs[count].nama);fflush(stdin);
		scanf("%d",&mhs[count].umur);fflush(stdin);
		count++;
	}
	tulisfile();
//		printf("Nama:");scanf("%[^\n]",&mhs[i].nama);fflush(stdin);	
//		printf("umur:");scanf("%d",&mhs[i].umur);fflush(stdin);
//		printf("Univ:");scanf("%[^\n]",&mhs[i].univ);fflush(stdin);
//		printf("Nama: %s\n",mhs[i].nama);
//		printf("Umur: %d\n",mhs[i].umur);
//		printf("univ: %s\n",mhs[i].univ);
//	}
	return 0;
}
