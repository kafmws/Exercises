//https://leetcode-cn.com/problems/n-queens-ii/
int isLegal(int *lines, int index){
    for(int i = 0;i<index;i++){
        if(i-index==lines[i]-lines[index]||index-i==lines[i]-lines[index])return 0;
    }
    return 1;
}

void swap(int *lines, int i, int j){
    int k = lines[i];
    lines[i] = lines[j];
    lines[j] = k;
}

void re(int i, int *lines, int num, int *cnt){
    if(i==num){
        (*cnt)++;
    }
    for(int j = i;j<num;j++){
        swap(lines,i,j);
        if(isLegal(lines,i)){
            re(i+1,lines,num,cnt);
        }
        swap(lines,i,j);
    }
}

int totalNQueens(int n){
    int lines[50];
    int cnt = 0;
    for(int i = 0;i<n;i++){
        lines[i] = i;
    }
    re(0,lines,n,&cnt);
    return cnt;
}