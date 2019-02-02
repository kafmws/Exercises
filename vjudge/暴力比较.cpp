#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//https://vjudge.net/contest/280657#problem/I

#define SIZE 1000
typedef struct{
	int x,y;
}pair;
//x、y写反   敲 
pair p[8][7]={{{1,0},{2,0},{0,1},{0,2},{1,2},{2,2},{2,1}},
				{{0,-1},{0,1},{1,-1},{1,1},{2,-1},{2,0},{2,1}},
				{{0,-2},{0,-1},{1,0},{2,0},{2,-1},{2,-2},{1,-2}},
/*	xxx	*/		{{1,0},{-1,0},{-1,-1},{1,-1},{-1,-2},{1,-2},{0,-2}},
/*	x.x	*/		{{-1,0},{-2,0},{0,-1},{0,-2},{-1,-2},{-2,-2},{-2,-1}},
/*	xxx	*/		{{0,-1},{0,1},{-1,-1},{-1,1},{-2,-1},{-2,1},{-2,0}},
/*	y→	*/		{{-1,0},{-2,0},{0,1},{0,2},{-1,2},{-2,1},{-2,2}},
/*	x↓	*/ 		{{1,0},{-1,0},{-1,1},{1,1},{-1,2},{1,2},{0,2}},};



			
int m,n;
char flag[SIZE][SIZE]={0};
char map[SIZE][SIZE];

void book(int pos, int x, int y){
	for(int i=0;i<7;i++)
		flag[x+p[pos][i].x][y+p[pos][i].y]==1;
}

int judge(int x, int y){//返回是否匹配
	int tx,ty;
	int i,j;
	if(x==2&&y==5){
		int xx;
		xx=x;
	}
	for(i = 0;i<8;i++){
		int flag = 1;
		for(j = 0;j<7;j++){
			tx = x+p[i][j].x;
			ty = y+p[i][j].y;
			if(tx>=m||ty>=n||tx<0||ty<0){
				flag=0;
				break;
			}
			if(map[tx][ty]!='#'){
				flag = 0;
				break;
			}
		}
		if(flag){//合适的位置 
			book(i,x,y);
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d %d%*c",&m,&n);
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			scanf("%c",&map[i][j]);
		}
		getchar();
	}
	for(int i = 0;i<m;i++){
		for(int j = 0;j<n;j++){
			if(map[i][j]=='#'&&flag[i][j]==0){
				if(judge(i,j)==0){
					//printf("(%d,%d)",i,j);
					printf("NO");
					return 0;
				}
			}
		}
	} 
	printf("YES");
	return 0;
} 
