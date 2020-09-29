#include <stdio.h>
int binary(int arr[], int n, int key) 
{ 
    int left = 0, right = n-1; 
    int mid; 
    int count=0;
    while (left <= right) 
    { 
        mid = (left +right)/2;
		//printf("Mid = %d\n",mid); 
        if (arr[mid] == key) 
        {
        count++;
		//printf("%d\n",count);
            while (arr[mid+1] == key && mid+1<n){
             	mid++;
				count++; 	
			}
			return count;
            break; 
        } 
        else if (key<arr[mid]){
        	right = mid-1; 
        	//printf("Right = %d\n",right);
		} 
        else if (key>arr[mid]){
        	left = mid + 1; 
        	//printf("Left = %d\n",left);
		}
    }
	if (left>right){
		return -1;
	} 
} 
int main(){
	int array[100005];
	int n,b;
	scanf("%d %d",&n,&b);
	for (int i=0; i<n; i++){
		scanf("%d",&array[i]);
	}
	int temp;
	int search;
	for (int i=0; i<b; i++){
		scanf("%d",&search);
		int temp=binary(array,n,search);
		if (temp==-1){
			printf("0\n");
		} 
		else{
			printf("%d\n",temp);
		}
		temp=0;
	}
}
