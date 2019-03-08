#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776

int main() {
	int n;
	scanf("%d",&n);
	int nums[105];
	for(int i = 0; i<n; i++) {
		scanf("%d",&nums[i]);
	}
	int num[100000]= {0};
	int tem = n;
	while(tem--) {
		int a = nums[tem];
		if(num[a])
			continue;
		while(a!=1) {	
			a = a%2==0?a>>1:(3*a+1)>>1;
			if(num[a])
				break;
			num[a]++;
		}
	}
	int result[105];
	int cnt = 0;
	for(int i = 0; i<n; i++) {
		if(num[nums[i]]==0)
			result[cnt++] = nums[i];
	}
	for(int i = 0; i<cnt-1; i++) {
		int max = i;
		for(int j = i+1; j<cnt; j++) {
			if(result[j]>result[max])
				max = j;
		}
		int t = result[max];
		result[max] = result[i];
		result[i] = t;
	}
	for(int i = 0;i<cnt-1;i++)
		printf("%d ",result[i]);
	printf("%d",result[cnt-1]);
	return 0;
}
