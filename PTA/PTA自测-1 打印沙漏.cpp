#include<stdio.h>

//https://pintia.cn/problem-sets/17/problems/260

int main() {
	int num;
	char c;
	scanf("%d %c", &num, &c);
	if (num == 0)
		return;
	int i = 1;
	while ((i + i * (i - 1)) * 2 - 1 < num)
		i ++;
	if ((i + i * (i - 1)) * 2 - 1 > num)
		i --;
	int left = num - (i + i * (i - 1)) * 2 + 1;
	int len = 2 * i - 1;
	for (i = 2 * i - 1; i >= 1; i -= 2) {
		for (int sp = (len - i) / 2; sp; sp--)
			printf(" ");
		for (int j = i; j; j--)
			printf("%c", c);
		printf("\n");
	}
	for (i = 3; i <= len; i += 2) {
		for (int sp = (len - i) / 2; sp; sp--)
			printf(" ");
		for (int j = 1; j <= i; j++)
			printf("%c", c);
		printf("\n");
	}
	printf("%d", left);
	return 0;
}
