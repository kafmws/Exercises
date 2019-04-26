#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {
	int x;
	int y;
	int fee;
	int oil;
}Status;

int dir[4][3] = { {-1,0,0},{0,-1,0},{1,0,0},{0,1,0} };//�������������� 

int main() {
	int N, K, A, B, C;
	scanf("%d%d%d%d%d", &N, &K, &A, &B, &C);
	dir[0][2] = dir[1][2] = B;//���˷��� 
	char map[105][105] = { 0 };
	int mapFee[105][105];
	int mapOil[105][105];//��¼�Ϻ�״̬�µķ��������� ��ֹ��ѭ��
	memset(mapFee, 0x3f, sizeof(mapFee));
	memset(mapOil, 0x3f, sizeof(mapOil));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	Status status[100000];
	int left = 0, right = 0;
	int tx, ty, tfee;
	int minFee = 0x3f3f3f3f;
	status[right++] = { 1,1,0,K };//��ʼ����ʼλ�� 
	mapFee[1][1] = 0;
	mapOil[1][1] = K;

	while (left <= right) {//BFS
		Status t = status[left++];
		if (t.x == N && t.y == N)continue;// && д�� ||��֪����ô�Ե� 
		for (int i = 0; i < 4; i++) {
			tx = t.x + dir[i][0];
			ty = t.y + dir[i][1];
			if (tx == N && ty == N) {//�����յ� 
				minFee = t.fee > minFee ? minFee : t.fee;
				break;
			}
			if (tx<1 || tx>N || ty<1 || ty>N)continue;
			status[right].x = tx;
			status[right].y = ty;
			status[right].oil = t.oil - 1;
			tfee = t.fee + dir[i][2];//�����շ�
			if (map[tx][ty] == 1) {//����վ 
				tfee += A;
				status[right].oil = K;
			}
			else if (t.oil == 1) {//��·û�� ǰ�汣֤(tx,ty)û���յ� 
				tfee += C + A;
				status[right].oil = K;
			}
			if (!(status[right].oil <= mapOil[tx][ty] && tfee >= mapFee[tx][ty])){
				mapFee[tx][ty] = tfee;
				mapOil[tx][ty] = status[right].oil;	
				status[right++].fee = tfee;
			}
		}
	}
	printf("%d\n", minFee);
	/*printf(" x\ty\tfee\toil\n");
	for (int i = 0; i <= right; i++) {
		printf("%2d\t%2d\t%3d\t%3d\n", status[i].x, status[i].y, status[i].fee, status[i].oil);
	}*/
	return 0;
} 
