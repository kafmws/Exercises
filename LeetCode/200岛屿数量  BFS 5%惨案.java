class Solution {

    private int n;
    private int m;

    class Pair{
        int x,y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private Pair findIsland(char[][] grid){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j]=='1')return new Pair(i,j);
            }
        }
        return null;
    }

    private int cntIsland(char[][] grid){
        int cnt = 0;
        Queue<Pair> queue = new LinkedList<>();
        Pair pair;
        while((pair=findIsland(grid))!=null){
            queue.add(pair);
            grid[pair.x][pair.y] = '0';
            cnt++;
            while(!queue.isEmpty()){
                Pair p = queue.remove();
                if(p.x+1<n&&grid[p.x+1][p.y]=='1'){//↓
                    queue.add(new Pair(p.x+1,p.y));
                    grid[p.x+1][p.y] = '0';
                }
                if(p.y+1<m&&grid[p.x][p.y+1]=='1'){//→
                    queue.add(new Pair(p.x,p.y+1));
                    grid[p.x][p.y+1] = '0';
                }
                if(p.y-1>=0&&grid[p.x][p.y-1]=='1'){//←
                    queue.add(new Pair(p.x,p.y-1));
                    grid[p.x][p.y-1] = '0';
                }
                if(p.x-1>=0&&grid[p.x-1][p.y]=='1'){//↑
                    queue.add(new Pair(p.x-1,p.y));
                    grid[p.x-1][p.y] = '0';
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