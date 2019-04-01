#include<stdio.h> 

int main(){
	int n,m;//数字个数，右移位数
	scanf("%d %d",&n,&m);
	m%=n;
	int num[1000];
	for(int i = 0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i = 0;i<m;i++){
		printf("%d ",num[(i+n-m)%n]);
	}
	for(int i = m;i<n-1;i++){
		printf("%d ",num[(i-m+n)%n]);
	}
	printf("%d",num[n-m-1]);
	return 0;
}
