/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0){*returnSize = 0; return (int *)NULL;};
    *returnSize = matrixSize * matrixColSize[0];
    int *num = malloc(sizeof(int)*(*returnSize));
    int i = 0, j = 0;
    int cnt = 0;
    int rowSize = matrixSize;
    int colSize = matrixColSize[0];
    while(cnt<(*returnSize)){
        while(j<colSize){//→
            num[cnt++] = matrix[i][j++];
        }
        j--;
        i++;
        if(cnt>=(*returnSize))break;
        while(i<rowSize){//↓
            num[cnt++] = matrix[i++][j];
        }
        i--;
        j--;
        if(cnt>=(*returnSize))break;
        while(j>=matrixColSize[0]-colSize){//←
            num[cnt++] = matrix[i][j--];
        }
        j++;
        i--;
        colSize--;
        rowSize--;
        if(cnt>=(*returnSize))break;
        while(i>=matrixSize-rowSize){//↑
            num[cnt++] = matrix[i--][j];
        }
        i++;
        j++;
    }
    return num;
}