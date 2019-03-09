#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//https://pintia.cn/problem-sets/17/problems/262

int main(){
	int N,n;
	scanf("%d%d",&N,&n);
	n%=N;
	int i;
	int num[N];
	for(i = 0;i<N;i++)
		scanf("%d",&num[i]);
	for(i=N-n;i<N-1;i++)
		printf("%d ",num[i]);
	if(n!=0){
		printf("%d ",num[N-1]);
		for(i = 0;i<N-n-1;i++)
			printf("%d ",num[i]);
		printf("%d",num[i]);
	}else{
		for(int i = 0;i<N-1;i++)
			printf("%d ",num[i]);
		printf("%d",num[N-1]);
		}
	return 0;
}
