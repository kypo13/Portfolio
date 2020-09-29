#include <stdio.h>
//Tipedata,variabel(parameter)
void menu(int angka,char nama[]){
	printf("Angkanya : %d %s\n\n",angka,nama);
	angka=5;
}

void edit(int &a1,int &a2){
	int temp;
	temp=a1;
	a1=a2;
	a2=temp;
}

void swap(int *a1,int *a2){
	int temp;
	temp=*a1;
	*a1=*a2;
	*a2=temp;
}

int hitung(int n){
	if (n==1)return 1;
	return n*hitung(n-1);//return n maksudnya hitung=n
}
int fibo (int a){
	if (a<=1)return 1;
	return fibo(a-1)+fibo(a-2);
}

int main()
{
//	char nama[20]={"andi"};
//	int angka=10;
//	int a1=5,a2=10;
//	
//	menu(angka,nama);//Passing by value
//	printf("Angka sebelum: %d %d\n",a1,a2);
//	edit(a1,a2);//Passing by references(alamat)
//	printf("Angka sesudah: %d %d\n",a1,a2);
//	
//	printf("a1=%d , a2=%d\n",a1,a2);
//	swap(&a1,&a2);//passing by pointer
//	printf("a1=%d , a2=%d\n",a1,a2);

	int n=5;
	int hasil;
	int a;
	//printf("%d",hitung(n));//faktorial
	//scanf("%d",&a);
	//printf("%d",fibo(a));
	
	int t1=0;
	int t2=1;
	int next;
	scanf("%d",&angka);
	
	for (int i=0;i<=angka;i++){
		next=t1+t2;
		t1=t2;
		t2=next;
	}
	return 0;
}
