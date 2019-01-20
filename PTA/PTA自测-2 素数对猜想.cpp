#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//https://pintia.cn/problem-sets/17/problems/261

int sqrt(int n) {
	for(int i = 1; i<n; i++)
		if((i+1)*(i+1)>n)
			return i;
}

int isPrime(int i) {
	if(i<2)
		return 0;
	for(int j=2; j<sqrt(i)+1; j++)
		if(i%j==0) {
			return 0;
		}
	return 1;
}

int isP(int n,int *list, int num) {
	for(int i = 0; i<num; i++) {
		if(n%list[i]==0)
			return 0;
	}
	return 1;
}

int main() {
	int N;
	int num = 0;
	scanf("%d",&N);
	int list[10000] = {0};
	for(int i = 2; i<=N; i++) {
		if(i<100&&isPrime(i)) {//
			list[num++] = i;
		}
		 else if(isP(i,list,num)) {
			list[num++] = i;
		}
	}
	int cnt = 0;
	for(int i = 0; i<num-1; i++) {
		if(list[i]+2 == list[i+1])
			cnt++;
	}
	printf("%d",cnt);
	return 0;
}
