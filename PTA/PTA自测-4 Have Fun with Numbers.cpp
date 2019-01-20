#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//https://pintia.cn/problem-sets/17/problems/263

int main(){
	int num[30];///////////////  num数组大小取 25,30,40结果不同 
	int n = 0;
	int c;
	int book[10]={0};
	while(scanf("%c",&c)&&c!='\n')
		num[n++]=c-'0';
	int t=0;
	for(int i=n-1;i>=0;i--){
		book[num[i]]++;
		num[i]=num[i]*2+t;
		t=num[i]/10;
		num[i]%=10;
	}
	
//	for(int i=0;i<n;i++)
//		printf("%d",num[i]);
//	printf("\n");
		
	for(int i = 0;i<n;i++)
		book[num[i]]--;
	int flag = 1;
	for(int i = 0;i<10;i++)
		if(book[i]){
			flag = 0;
			break;
		}
	t||flag==0?printf("No\n"):printf("Yes\n");
	if(t){
		book[t]--;
		printf("%d",t);
	}
	for(int i = 0;i<n;i++){
		book[num[i]]--;
		printf("%d",num[i]);
	}
}
