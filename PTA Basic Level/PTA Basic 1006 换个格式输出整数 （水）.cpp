#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//https://pintia.cn/problem-sets/994805260223102976/problems/994805318855278592

int main() {
	char str[10]={'0','0','0',0};
	char s[4];
	scanf("%s",s);
	int gap = 3-strlen(s);
	sprintf(str+gap,"%s",s);
	for(int i = 0; i<strlen(str); i++) {
		int cnt = str[i]-'0';
		int ccnt = cnt;
		while(cnt--) {
			switch(i) {
				case 0:printf("B");
					break;
				case 1:printf("S");
					break;
				case 2:
					for(int j = 1;j<=ccnt;j++)
						printf("%d",j);
						return 0;
					break;
			}
		}
	}
	return 0;
}
