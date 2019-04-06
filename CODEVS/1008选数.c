#include<stdio.h>
#include<math.h>
#define SIZE 10000

int n,k;
int num[10000] = {0};
int cache[SIZE]={0};
int cacheSize = 0;
int cnt = 0;

int isPrime(int n){
	if(n<2)return 0;
	for(int i = 0;i<cacheSize;i++){
		if(cache[i]==n){
			cnt++;
			return 1;	
		}
	}
	for(int i = 2;i<=sqrt(n);i++){
		if(n%i==0)return 0;
	}
	if(cacheSize<SIZE){
		cache[cacheSize++] = n;
		cnt++;	
	}
	return 1;
}

void sum(int tem, int time, int index){
	if(time==k)isPrime(tem);
	else{
		for(;index<n;index++){
			sum(tem+num[index], time+1, index+1);
		}
	}
}

int main(){
	scanf("%d %d",&n,&k);
	for(int i = 0;i<n;i++){
		scanf("%d",&num[i]);
	}
	sum(0,0,0);
	printf("%d\n",cnt);
	return 0;
}
