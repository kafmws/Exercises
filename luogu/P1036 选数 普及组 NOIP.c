#include<stdio.h>

int cnt = 0;
int result = 0;
int primes[30000]={0};
int numSize = 0, k;

int isPrime(int num){
	if(num<2)return 0;
	if(num==2)return 1;
	for(int i = 2;i<=sqrt(num);i++){
		if(num%i==0)return 0;
	}
	return 1;
}

void joinPrimes(int num){
	for(int i = 0;i<cnt;i++){
		if(primes[i]==num)return;
	}
	primes[cnt++] = num;
}

void select(int *num, int currentIndex,int currentK, int sum){// 
	currentK++;
	if(currentK==k){
		for(int i = currentIndex;i<numSize;i++){
			if(isPrime(sum+num[i])){
				result++;
				joinPrimes(sum+num[i]);
			}
		}
	}else{
		for(int i = currentIndex;i<numSize;i++){
			select(num, i+1, currentK, sum+num[i]);
		}
	} 
} 

int main(){
	int num[20]={0};
	scanf("%d%d",&numSize,&k);
	for(int i = 0;i<numSize;i++){
		scanf("%d",&num[i]);
	}
	select(num,0,0,0);
	printf("%d",result);
	return 0;
} 