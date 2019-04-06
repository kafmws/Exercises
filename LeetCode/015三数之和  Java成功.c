/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define SIZE 16300

int compare(const void *p1, const void *p2){
    return *((int *)p1) - *((int *)p2);
}

int judge(int **re, int cnt, int a, int b){
    if(cnt>0)
        cnt--;
    while(re[cnt][0]==a){
        if(re[cnt][1]==b)
            return 0;
        cnt--;
    }
    return 1;
}

int** threeSum(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    int cnt = 0;
    qsort(nums,numsSize,sizeof(int),compare);
    if(numsSize<3)
        return NULL;
    int **re = (int **)malloc(sizeof(int *)*SIZE);
    for(int i = 0;i<SIZE;i++){
        re[i] = (int *)malloc(sizeof(int)*3);
    }
    for(int i = 0 ;nums[i]<=0&&i<numsSize-2;i++){
        int j = i + 1, k = numsSize - 1;
        while(j<k){
            int t = nums[i]+nums[j]+nums[k];
            if(t>0)
                k--;
            else if(t==0)
                if(judge(re,cnt,nums[i],nums[j])){
                    re[cnt][0] = nums[i];
                    re[cnt][1] = nums[j];
                    re[cnt][2] = nums[k];
                    cnt++;
                    j++;
                    k--;
                }
            else
                j++;
        }
    }
    *returnSize = cnt;
    return re;
}