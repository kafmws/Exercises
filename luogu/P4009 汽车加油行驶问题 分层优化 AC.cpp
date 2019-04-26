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

int dir[4][3] = { {-1,0,0},{0,-1,0},{1,0,0},{0,1,0} };//←，↑，→，↓ 

int main() {
	int N = 0, K = 0, A = 0, B = 0, C = 0;
	scanf("%d%d%d%d%d", &N, &K, &A, &B, &C);
	dir[0][2] = dir[1][2] = B;//回退费用 
	char map[105][105] = { 0 };
	int mapOilFee[105][105][15];//一二维x, y, 第三维下标oil 值fee 记录较好状态下的油量与对应的费用 防止死循环
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
	mapOilFee[1][1][K] = 0;//油量为K时fee==0
	status.push(t);

	while (status.size() != 0) {//BFS
		t = status.front();
		status.pop();
		if (t.x == N && t.y == N)continue;
		for (int i = 0; i < 4; i++) {
			tx = t.x + dir[i][0];
			ty = t.y + dir[i][1];
			if (tx == N && ty == N) {//到达终点 
				minFee = t.fee > minFee ? minFee : t.fee;
				break;
			}
			if (tx<1 || tx>N || ty<1 || ty>N)continue;
			Status tem = { tx,ty,0,t.oil - 1 };
			tfee = t.fee + dir[i][2];//方向收费
			if (map[tx][ty] == 1) {//加油站 
				tfee += A;
				tem.oil = K;
			}
			else if (t.oil == 1) {//半路没油 前面保证(tx,ty)没到终点 
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
