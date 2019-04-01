#include<stdio.h> 

int main() {
	int list[11000] = { 2,3,5,7 };
	int begin, end;
	scanf("%d %d", &begin, &end);
	for (int i = 4, num = 11; i <= end; num++) {
		int flag = 1;
		for (int j = 0; j < i; j++) {
			if (num%list[j] == 0) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			list[i++] = num;
		}
	}
	for (int i = begin - 1, cnt = 0; i < end; i++) {
		printf("%d", list[i]); 
		cnt++;
		if (cnt == 10&& i != end - 1) {
			printf("\n"); cnt = 0;
		}
		else if(i!=end-1){
			printf(" ");
		}
	}
	return 0;
}