class Solution {
    
    boolean judgeRow(char map[][]){
        
        // for(int i = 0;i<9;i++){
        //     for(int j = 0;j<9;j++){
        //         System.out.printf("%c ",map[i][j]);
        //     }
        //     System.out.println();
        // }
        
        
        for(int i = 0;i<9;i++){
            int []judge= new int [10];
            for(int j = 0;j<9;j++){
                if(map[i][j]!=46){
                    if(judge[map[i][j]-'0']!=0){
                        // System.out.print(1);
                        return false;
                    }
                    else judge[map[i][j]-'0']++;
                }
                
            }
        }
        return true;
    }

    boolean judgeCol(char map[][]){
        for(int i = 0;i<9;i++){
            int []judge= new int [10];
            for(int j = 0;j<9;j++){
                if(map[j][i]!=46){
                    if(judge[map[j][i]-'0']!=0){
                        // System.out.print(2);
                        return false;
                    }
                    else judge[map[j][i]-'0']++;
                }
            }
        }
        return true;
    }

    boolean judgeBlock(char map[][]){
        for(int i = 0;i<9;i+=3){
            for(int j = 0;j<9;j+=3){//取得每个block的首位置
                int []judge= new int [10];
                for(int p = i;p<i+3;p++){
                    for(int q = j;q<j+3;q++){
                        if(map[p][q]!=46){
                            if(judge[map[p][q]-'0']!=0){
                                // System.out.print(3);
                                return false;
                            }
                            else judge[map[p][q]-'0']++;
                        }
                    }
                }
            }
        }
        return true;
    }

    public boolean isValidSudoku(char[][] board) {
        return judgeRow(board)&&judgeCol(board)&&judgeBlock(board);
    }
}