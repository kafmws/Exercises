// luogu-judger-enable-o2
#include<stdio.h>

int redis[10000]={0};

int re(int n){
	if(n==1){
		return 0;
	}
	if(redis[n]){
		return redis[n];
	}
	int cnt = 0;
	for(int i = n/2;i>0;i--){
		cnt++;
		cnt += re(i);
	}
	redis[n] = cnt;
	return cnt;
}

int main() {
	int num;
	scanf("%d",&num);
	printf("%d",re(num)+1);
	return 0;
}
