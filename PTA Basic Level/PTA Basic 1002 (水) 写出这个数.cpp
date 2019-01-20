#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384

int main(){
	char c;
	int sum = 0;
	while(scanf("%c",&c)&&c!=10){
		sum+=c-'0';
	}
	char num[1000];
	sprintf(num,"%d",sum);//分离出数的每一位 
	char str[][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int i = 0;
	for(;i<strlen(num)-1;i++)
		printf("%s ",str[num[i]-'0']);
	printf("%s",str[num[i]-'0']);
	return 0;
} 
