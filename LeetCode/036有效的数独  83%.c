int judgeRow(char **map){
    for(int i = 0;i<9;i++){
        int judge[10]={0};
        for(int j = 0;j<9;j++){
            if(map[i][j]!='.'){
                if(judge[map[i][j]-'0']){
                    return 0;   
                }else{
                    judge[map[i][j]-'0']++;
                }
            }
        }
    }
    return 1;
}

int judgeCol(char **map){
    for(int i = 0;i<9;i++){
        int judge[10]={0};
        for(int j = 0;j<9;j++){
            if(map[j][i]!='.'){
                if(judge[map[j][i]-'0']){
                    return 0;
                }else
                    judge[map[j][i]-'0']++;
            }
        }
    }
    return 1;
}

int judgeBlock(char **map){
    for(int i = 0;i<9;i+=3){
        for(int j = 0;j<9;j+=3){//取得每个block的首位置
            int judge[10]={0};
            for(int p = i;p<i+3;p++){
                for(int q = j;q<j+3;q++){
                    if(map[p][q]!='.'){
                        if(judge[map[p][q]-'0']){
                            return 0;              
                        }else
                            judge[map[p][q]-'0']++;
                    }
                }
            }
        }
    }
    return 1;
}

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    return judgeRow(board)&&judgeCol(board)&&judgeBlock(board);
}