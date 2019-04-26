#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

typedef struct {
	int x;
	int y;
	int fee;
	int oil;
}Status;

int dir[4][3] = { {-1,0,0},{0,-1,0},{1,0,0},{0,1,0} };//�������������� 

int main() {
	int N = 0, K = 0, A = 0, B = 0, C = 0;
	scanf("%d%d%d%d%d", &N, &K, &A, &B, &C);
	dir[0][2] = dir[1][2] = B;//���˷��� 
	char map[105][105] = { 0 };
	int mapOilFee[105][105][15];//һ��άx, y, ����ά�±�oil ֵfee ��¼�Ϻ�״̬�µ��������Ӧ�ķ��� ��ֹ��ѭ��
	memset(mapOilFee, 0x3f, sizeof(mapOilFee));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	queue<Status> status;
	int tx, ty, tfee;
	int minFee = 0x3f3f3f3f;
	Status t = { 1,1,0,K };
	mapOilFee[1][1][K] = 0;//����ΪKʱfee==0
	status.push(t);

	while (status.size() != 0) {//BFS
		t = status.front();
		status.pop();
		if (t.x == N && t.y == N)continue;
		for (int i = 0; i < 4; i++) {
			tx = t.x + dir[i][0];
			ty = t.y + dir[i][1];
			if (tx == N && ty == N) {//�����յ� 
				minFee = t.fee > minFee ? minFee : t.fee;
				break;
			}
			if (tx<1 || tx>N || ty<1 || ty>N)continue;
			Status tem = { tx,ty,0,t.oil - 1 };
			tfee = t.fee + dir[i][2];//�����շ�
			if (map[tx][ty] == 1) {//����վ 
				tfee += A;
				tem.oil = K;
			}
			else if (t.oil == 1) {//��·û�� ǰ�汣֤(tx,ty)û���յ� 
				tfee += C + A;
				tem.oil = K;
			}
			tem.fee = tfee;
			if (tfee < mapOilFee[tx][ty][tem.oil]) {
				status.push(tem);
				mapOilFee[tx][ty][tem.oil] = tfee;
			}
		}
	}
	printf("%d", minFee);
	return 0;
}
