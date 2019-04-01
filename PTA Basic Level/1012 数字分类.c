#include<stdio.h> 

int main() {
	int a[5] = { 0 };
	int flags[5] = { 0 };
	int n, num;
	int flag = 1;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		switch (num%5){
		case 0:if ((num % 2) == 0) { a[0] += num; flags[0] = 1;} break;
		case 1:flags[1] = 1; flag == 1 ? (a[1] += num) : (a[1] -= num); flag *= -1; break;
		case 2:flags[2] = 1; a[2]++; break;
		case 3:flags[3] = 1; a[3] += num; cnt++; break;
		case 4:flags[4] = 1; if (num > a[4])a[4] = num;
		default:
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		if (i != 0) {
			printf(" ");
		}
		if (flags[i]) {
			if (i != 3)printf("%d", a[i]); else printf("%.1f", a[3]/(cnt*1.0));
		}
		else {
			printf("N");
		}
	}
	return 0;
}