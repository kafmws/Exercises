#define SIZE 1024

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int* columnSizes = *returnColumnSizes = (int *)malloc(sizeof(int)*SIZE);//记录每个数组的长度
    // columnSizes[0]=columnSizes[1]=1;
    int **re = (int **)malloc(sizeof(int *)*1000);
    for(int i = 0;i<1000;i++){
        re[i] = (int *)malloc(sizeof(int)*SIZE);
        memset(re[i],0,sizeof(re[i]));
    }//遍历结果，二维数组
    
    struct TreeNode* queue[SIZE]={0};
    struct TreeNode* pueue[SIZE]={0};
    struct TreeNode **q = queue, **p = pueue, **t = NULL;
    
    int i = 0, j = 0, size, newSize;
    if(root)q[size++] = root;
    
    while(size||newSize){
        while(i<size){
            re[*returnSize][j++] = q[i]->val;
            if(q[i]->left)p[newSize++] = q[i]->left;
            if(q[i]->right)p[newSize++] = q[i]->right;
            i++;
        }
        columnSizes[(*returnSize)++] = j;
        size = newSize;
        newSize = 0;
        t = p, p = q, q = t;
        i = j = 0;
    }
    return re;
}

