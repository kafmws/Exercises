#include<stdio.h> 

int main() {
	int cnt = 0;
	double a, b, c;
	scanf("%d", &cnt);
	for (int i = 1; i <= cnt; i++) {
		scanf("%lf %lf %lf", &a, &b, &c);
		printf("Case #%d: ", i);
		if (a + b > c)printf("true");
		else printf("false");
		if (i != cnt)
			printf("\n");
	}
	return 0;
}