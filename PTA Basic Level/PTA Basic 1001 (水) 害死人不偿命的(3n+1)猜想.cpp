#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528 

int main(){
	int n;
	scanf("%d",&n);
	int cnt = 0;
	while(n!=1){
		n = n%2==0?n>>1:(n*3+1)>>1;
		cnt++;
	}
	printf("%d",cnt);
	return 0;
} 
