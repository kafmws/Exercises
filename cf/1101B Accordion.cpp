#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//http://codeforces.com/contest/1101/problem/B

int index_of(char *s, int begin, int end,char c){
	for(int i = begin;i<=end;i++){
		if(s[i]==c)
			return i;
	}
	return -1;
}

int index_of_re(char *s, int left, int right, char c){//´ÓÓÒÏò×ó 
	for(int i = right;i>=left;i--){
		if(s[i]==c)
			return i;
	}
	return -1;
}

int cnt(char *s, int begin, int end){
	int num=4;
	int left = index_of(s,begin+1,end,':');
	if(left==-1)
		return -1;
	int right = index_of_re(s,left+1,end,':');
	if(right==-1)
		return -1;
	for(left++;left<right;left++)
		if(s[left]=='|')
			num++;
	return num;
}

int main(){
	char s[500005]; 
	scanf("%s",s);
	int len = strlen(s);
	int re = -1;
	int left = index_of(s,0,len-1,'[');
	int right = index_of_re(s,0,len-1,']');
	if(left+3<=right&&left!=-1&&right!=-1)
		re = cnt(s,left,right);
	printf("%d",re);
	return 0;
} 
