#include<stdio.h>
int reverse(int num){
	int rev=0,rem,i;
	if(num>0){
		while(num>0){
		rem=num%10;
		rev=rev*10+rem;
		num/=10;
	}
	return rev;	  
}
}
int main(){
	int n;
	printf("Enter the number:");
	scanf("%d",&n);
	int rev=reverse(n);
	printf("The reverse of a number is:%d",rev);
}
