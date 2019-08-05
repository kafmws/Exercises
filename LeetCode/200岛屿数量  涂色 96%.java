class Solution {

    private int n;
    private int m;
    char[][] grid;

    private void paint(int i, int j) {
        if(i+1<n&&grid[i+1][j]=='1'){//↓
            grid[i+1][j]='0';
            paint(i+1,j);
        }
        if(j+1<m&&grid[i][j+1]=='1'){//→
            grid[i][j+1]='0';
            paint(i,j+1);
        }
        if(j-1>=0&&grid[i][j-1]=='1'){//←
            grid[i][j-1]='0';
            paint(i,j-1);
        }
        if(i-1>=0&&grid[i-1][j]=='1'){//↑
            grid[i-1][j]='0';
            paint(i-1,j);
        }
    }

    private int cntIsland(char[][] grid){
        int cnt = 0;
        this.grid =grid;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    paint(i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public int numIslands(char[][] grid) {
        if(grid.length==0||grid[0].length==0)return 0;
        n = grid.length;
        m = grid[0].length;
        return cntIsland(grid);
    }

}