#include<stdio.h>

int main(){
 int angka[9999]={0};
 int i=0;
 FILE *f = fopen("testdata.in","r");
 //freopen("testdata.in","r",stdin);
 while (!feof(f)){
  fscanf(f,"%d ",&angka[i]);
  i++;
 }
 fclose(f); 
 int max,min,range;
 double mean;
 int sum = 0;
 min=10000;max=-10000;
 for (int j=0;j<i;j++)
 {
  if (min>angka[j]){
   min=angka[j];
  }
  if (max<angka[j]){
   max=angka[j];
  }
  sum = sum + angka[j];
 }
  
 range=max-min;
 
 double temp = sum;
 double temp2 = i;
 
 mean = temp / temp2;
 
 printf("Count : %d\n",i);
 printf("Sum   : %ld\n",sum);
 printf("Mean  : %.2lf\n",mean); 
 printf("Min   : %d\n",min);
 printf("Max   : %d\n",max);
 printf("Range : %d\n",range);
 return 0;
}
