#include<stdio.h>
int main(){
	int num,i,sum=0;
	printf("Enter the number:");
	scanf("%d",&num);
	for(i=1;i<num;i++){
		if(num%i==0)
			sum=sum+i;
		
	}
	if(sum==num){
		printf("Perfect number");
	}
	else{
		printf("Not a perfect Number");
	}
}

