#include<stdio.h>
int main(){
	int size;
	printf("Enter the size:");
	scanf("%d",&size);
	int arr[size];
	printf("Enter the array elements:\n");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	for(int i=0;i<size;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	printf("The largest element is %d",max);
}
