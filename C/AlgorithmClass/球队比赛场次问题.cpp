#include<stdio.h>
//已知有n个球队， 每轮两个队比赛，胜者和轮空的队伍进入下一轮，求总共进行的比赛场数和轮数 
void infer(int *n, int *c, int *l) {
	if (*n == 1) {
		return;
	}
	else if ((*n) % 2 == 0) { //偶数
		(*c) += (*n) / 2;
		(*n) = (*n) / 2;
	}
	else {
		(*c) += (*n) / 2;
		(*n) = (*n) / 2 + 1;
	}
	(*l)++;
	infer(n, c, l);
}

int main() {
	int i = 1;
	int n, c, l;
	while (i++ < 100000000) {
		n = i, c = 0, l = 0;//球队数，场次，轮数
		infer(&n, &c, &l);
		if (c == i - 1) {
//			printf("1");
		}
		else {
			printf("false");
		}
	}
}
