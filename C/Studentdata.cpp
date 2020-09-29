#include<stdio.h>
struct siswa{
	char nama[1002][1002];char ad[1002][1002];
	int tgl[1002],bln[1002],thn[5002];
};
int main(){
	int n,id,byk,adid;
	struct siswa sis;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&id);
		scanf("%d %d %d %s %s",&sis.tgl[id],&sis.bln[id],&sis.thn[id],sis.nama[id],sis.ad[id]);
	}
	scanf("%d",&byk);
	for (int j=1;j<=byk;j++){
		scanf("%d",&adid);
		if (sis.tgl[adid]==NULL||sis.bln[adid]==NULL||sis.thn[adid]==NULL||sis.nama[adid]==NULL||sis.ad[adid]==NULL){
			printf("No data found!\n");
		}
		else printf("%d. %s was born on %d/%d/%d and live at %s\n",adid,sis.nama[adid],sis.tgl[adid],sis.bln[adid],sis.thn[adid],sis.ad[adid]);
	}
}
