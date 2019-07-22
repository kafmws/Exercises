
//https://leetcode-cn.com/problems/unique-paths-ii/submissions/

class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0]==1)return 0;
        obstacleGrid[0][0] = 1;
        int t = 1;
        for(int i = 1;i<obstacleGrid.length;i++){
            if(obstacleGrid[i][0]==1){
                t = 0;
            }
            obstacleGrid[i][0] = t;
        }
        t = 1;
        for(int j = 1;j<obstacleGrid[0].length;j++){
            if(obstacleGrid[0][j]==1){
                t = 0;
            }
            obstacleGrid[0][j] = t;
        }
        for(int i = 1;i<obstacleGrid.length;i++){
            for(int j = 1;j<obstacleGrid[0].length;j++){
                if(obstacleGrid[i][j]==1){obstacleGrid[i][j]=0;continue;}
                obstacleGrid[i][j] = obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[obstacleGrid.length-1][obstacleGrid[0].length-1];
    }
}

/**
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0]==1)return 0;
        int[][] map = obstacleGrid;
        for(int i = 1;i<obstacleGrid.length;i++){
            if(obstacleGrid[i][0]==1){
                map[i][0] = 0;
            }
            else map[i][0] = 1;
        }
        for(int j = 1;j<obstacleGrid[0].length;j++){
            if(obstacleGrid[0][j]==1){
                map[0][j] = 0;
            }
            map[0][j] = 1;
        }
        for(int i = 1;i<obstacleGrid.length;i++){
            for(int j = 1;j<obstacleGrid[0].length;j++){
                if(obstacleGrid[i][j]==1){map[i][j]=0;continue;}
                map[i][j] = map[i-1][j]+map[i][j-1];
            }
        }
        return map[obstacleGrid.length-1][obstacleGrid[0].length-1];
    }
}**/