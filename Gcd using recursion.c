#include<stdio.h>
int gcd(int a,int b){
	if(b==0)
	  return a;
	return gcd(b,a%b);
}
int main(){
	int num1,num2;
	printf("Enter two numbers:");
	scanf("%d %d",&num1,&num2);
	printf("GCD of two numbers is:%d\n",gcd(num1,num2));
	return 0;
}
