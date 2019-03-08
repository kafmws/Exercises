#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//https://pintia.cn/problem-sets/17/problems/264

void shuffle(int *order, int *index, int n){//use order to shuffle the index
	int tem[55];
	for(int i = 1;i<n;i++){
		tem[order[i]] = index[i];
	}
	for(int i = 1;i<n;i++){
		index[i] = tem[i];
		//printf("%d ",i,index[i]);
	}
	//printf("\n");
} 

int main(){
	char cards[55][4];
	for(int i = 1;i<=13;i++)
	 sprintf(cards[i],"S%d",i);
	for(int i = 14;i<=26;i++)
	 sprintf(cards[i],"H%d",i-13);
	for(int i = 27;i<=39;i++)
	 sprintf(cards[i],"C%d",i-26);
	for(int i = 40;i<=52;i++)
	 sprintf(cards[i],"D%d",i-39);
	sprintf(cards[53],"J1");
	sprintf(cards[54],"J2");
	int index[55],order[55];
	int times;
	scanf("%d",&times);
	for(int i = 1;i<=54;i++){
		index[i] = i;
		scanf("%d",&order[i]);
	}
	for(int i = 0;i<times;i++){
		shuffle(order,index, 55);
	}
	for(int i = 1;i<54;i++){
		printf("%s ",cards[index[i]]);
	}
	printf("%s",cards[index[54]]);
	return 0;
}
