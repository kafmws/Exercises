#include<stdio.h>
//��֪��n����ӣ� ÿ�������ӱ�����ʤ�ߺ��ֿյĶ��������һ�֣����ܹ����еı������������� 
void infer(int *n, int *c, int *l) {
	if (*n == 1) {
		return;
	}
	else if ((*n) % 2 == 0) { //ż��
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
		n = i, c = 0, l = 0;//����������Σ�����
		infer(&n, &c, &l);
		if (c == i - 1) {
//			printf("1");
		}
		else {
			printf("false");
		}
	}
}
