#include <stdio.h>
/*int main()
{
 	double x1,x2,x3;
	int i;

	for (i=1;i<=3;i++){
		scanf("%lf",&x1);
		scanf("%lf",&x2);
		scanf("%lf",&x3);
		if (x1<999&&x2<999&&x3<999){
		
		printf("%.3lf...\n",x1/999);
		printf("%.3lf...\n",x2/999);
		printf("%.3lf...\n",x3/999);
	}
	else printf("inputan harus dibawah 999");
}
	return 0;
} */

int main(){
	int t,i,a;
	for(i=1;i<=3;i++){
		scanf("%d",&t);
		//a%10 untuk cek angka belakang
		//a/100 untuk cek angka depan
		//(a/10)%10 untuk cek angka tengah
		if (t/100== t%10 && t/100==(t/10)%10){
		printf("0.%d...\n",t/100);
		}
		else {
			printf("0.%03d...\n",t);
		}
	}
	
	return 0;
}
