#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448

int main(){
	int n;
	scanf("%d",&n);
	int max=-1, min=0x7ffffff;
	char name1[100],name2[100],result1[1000],result2[1000];
	int score;
	int cnt = 0;
	while(cnt<n){
		scanf("%s %s %d",name1,name2,&score);
		if(score>max){
			max = score;
			sprintf(result1,"%s %s",name1,name2);
		}
		if(score<min){
			min = score;
			sprintf(result2,"%s %s",name1,name2);
		}
		cnt++;
	}
	puts(result1);
	printf("%s",result2);
	return 0;
} 
