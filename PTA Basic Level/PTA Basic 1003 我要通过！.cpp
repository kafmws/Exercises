#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192

int indexOf(char *s, char c){
	for(int i = 0;i<strlen(s);i++)
		if(s[i]==c)
			return i;
	return -1;
}

int judge(char *s){
	for(int i = 0;i<strlen(s);i++)
		if(s[i]!='A'&&s[i]!='P'&&s[i]!='T')
			return 0;
	int p = indexOf(s,'P');
	int t = indexOf(s,'T');
	if(p==-1||t==-1||fabs(p-t)==1)
		return 0;
	int midA = t-p-1;
	int preA = p;
	int postA = strlen(s)-t-1;
	if(midA*preA!=postA)
		return 0;
	return 1;
}

int main() {
	char s[1000];
	int n,count = 0;
	scanf("%d",&n);
	while(count<n) {
		scanf("%s",s);
		count++;
		if(judge(s))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
