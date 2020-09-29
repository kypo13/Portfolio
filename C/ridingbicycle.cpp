#include<stdio.h>
#include<math.h>
int main(){
    int n;
    double waktujalan;
	double waktukelas,waktubutuh;
    int velo,jarak,jam,menit;
	int jamnow;
	double menitnow,tempmenit;
    scanf("%d",&n);fflush(stdin);
    for (int i=1;i<=n;i++){
        scanf("%d %d %d:%d",&velo,&jarak,&jam,&menit);fflush(stdin);
        
		waktujalan=(double)jarak/(double)velo;
		
		waktujalan=waktujalan*60;
        waktukelas=(jam*60)+menit;
        waktubutuh=waktukelas-waktujalan;
    	
        tempmenit=waktubutuh;
		while(tempmenit>=60){
			tempmenit-=60;
		}
		menitnow=tempmenit;
        jamnow=(waktubutuh-menitnow)/60;
		while(menitnow<0){
        	menitnow+=60;
        	jamnow-=1;
		}
		while(jamnow<0){
			jamnow+=24;
		}
        printf("Case #%d: %02d:%02d\n",i,jamnow,(int)menitnow);
    }
    return 0;
}
