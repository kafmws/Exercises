//https://leetcode-cn.com/problems/spiral-matrix-ii/submissions/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    *returnSize = n;
    *returnColumnSizes = malloc(sizeof(int)*n);
    int **re = malloc(sizeof(int *)*n);
    int i, j, t;
    for(i = 0;i<n;i++){
        (*returnColumnSizes)[i] = n;
        re[i] = malloc(sizeof(int)*n);
    }
    int cnt = 0, nn = n*n;
    i = j = 0;
    for(t = 0;t<n;t++)re[i][j++] = ++cnt;
    j--;
    n--;
    while(1){
        for(t = 0;t<n;t++)re[++i][j] = ++cnt;
        for(t = 0;t<n;t++)re[i][--j] = ++cnt;
        if(cnt == nn)break;
        n--;
        for(t = 0;t<n;t++)re[--i][j] = ++cnt;
        for(t = 0;t<n;t++)re[i][++j] = ++cnt;
        if(cnt == nn)break;
        n--;
    }
    return re;
}

