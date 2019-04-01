#include<stdio.h> 

int main() {
	char str[1000][100] = {0};
	int cnt = 0;
	while (scanf("%s", str[cnt++]) != EOF);
	for (cnt = cnt - 2; cnt > 0; cnt--) {//-2？ EOF最后应该也进行了++
		printf("%s ", str[cnt]);
	}
	printf("%s", str[0]);
	return 0;
}
