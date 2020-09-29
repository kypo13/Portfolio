#include<stdio.h>

int pangkat(int angka,int angka2){
	
	if (angka2!=0){
		return angka * pangkat(angka,angka2-1);
	}
	else return 1;
}

int main(){
	int hasil;
	int angka=2,angka2=3;
	hasil=pangkat(angka,angka2);
	printf("%d",hasil);
	return 0;
}
