#include<stdio.h> 

int main() {
	int num, index;
	int flag = 0;
	while (scanf("%d %d", &num, &index)!=EOF) {
		if (index != 0) {
			if (flag) printf(" ");
			printf("%d %d", num*index, index - 1);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("0 0");
	}
	return 0;
}