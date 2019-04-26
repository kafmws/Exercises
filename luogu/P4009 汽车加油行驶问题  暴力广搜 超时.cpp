#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct {
	int x;
	int y;
	int fee;
	int oil;
}Status;

int dir[4][3] = { {-1,0,0},{0,-1,0},{1,0,0},{0,1,0} };//←，↑，→，↓ 

int main() {
	int N, K, A, B, C;
	scanf("%d%d%d%d%d", &N, &K, &A, &B, &C);
	dir[0][2] = dir[1][2] = B;//回退费用 
	char map[105][105] = { 0 };
	int mapFee[105][105];
	int mapOil[105][105];//记录较好状态下的费用与油量 防止死循环
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
	status[right++] = { 1,1,0,K };//初始化起始位置 
	mapFee[1][1] = 0;
	mapOil[1][1] = K;

	while (left <= right) {//BFS
		Status t = status[left++];
		if (t.x == N && t.y == N)continue;// && 写成 ||不知道怎么对的 
		for (int i = 0; i < 4; i++) {
			tx = t.x + dir[i][0];
			ty = t.y + dir[i][1];
			if (tx == N && ty == N) {//到达终点 
				minFee = t.fee > minFee ? minFee : t.fee;
				break;
			}
			if (tx<1 || tx>N || ty<1 || ty>N)continue;
			status[right].x = tx;
			status[right].y = ty;
			status[right].oil = t.oil - 1;
			tfee = t.fee + dir[i][2];//方向收费
			if (map[tx][ty] == 1) {//加油站 
				tfee += A;
				status[right].oil = K;
			}
			else if (t.oil == 1) {//半路没油 前面保证(tx,ty)没到终点 
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
