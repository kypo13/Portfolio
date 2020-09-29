/*Latihan Selection 

Buatlah coding:
A. Membedakan ganjil g enap
B. Menghitung pajak. 
Input : penghasilan bulanan, jumlah istri dan anak
Pajak per tahun menggunakan rumus pajak di Indonesia.
Output : pajak yang dikenakan dan gaji bersih.

Aturan penghasilan pertahun tidak kena pajak :
1. Rp54 juta per tahun untuk WP- wajib pajak orang pribadi.
2. Rp54 juta + Rp4,5 juta bagi wajib pajak yang menikah tanpa anak.
3. Rp54 juta + Rp4,5 juta + Rp4,5 juta bagi wajib pajak anak satu. Tambahan Rp4,5 juta diberlakukan untuk satu tanggungan, paling banyak tiga orang. 

Tarif Pajak:
1. Tarif pajak 5 persen dibebankan bagi WP dengan penghasilan tahunan mencapai Rp50 juta.
2. Tarif pajak 15 persen dibebankan bagi WP dengan penghasilan tahunan di atas Rp50 juta hingga Rp250 juta.
3. Tarif pajak 25 persen dibebankan bagi WP dengan penghasilan tahunan di atas Rp250 juta hingga Rp500 juta.
4. Tarif pajak 30 persen dibebankan bagi WP dengan penghasilan tahunan di atas Rp500 juta.
5. Bagi WP yang tak memiliki NPWP, maka dikenai tarif 20 persen lebih tinggi.

Semoga selain kemampuan programming, pengetahuan tentang perpajakan juga menjadi pengalaman untuk kalian.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int pil;
	printf("Menu tugas ESSE\n");
	printf("1. Membedakan ganjil genap\n");
	printf("2. Menghitung pajak\n");
	printf("Masukkan pilihan menu=");scanf("%d",&pil);
	switch (pil){
	
	
		case 1:
			int angka;
			printf("masukkan angka=");scanf("%d",&angka);
			if (angka%2==0){
				printf("Angka ini adalah bilangan genap");
			} else
			printf("Angka ini adalah bilangan ganjil");
			
		
		case 2:
			int jmlis,an;
			float pbl,pajak,gaji;
			
			
	
}
	return 0;
}
