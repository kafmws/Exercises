typedef struct {
    int *nums;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray *)malloc(sizeof(NumArray));
    obj->nums = nums;
    return obj;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    // printf("%d %d\n",i,j);
    int *nums = obj->nums;
    int re = 0;
    for(;i<=j;i++){
        // printf("%d \n",nums[i]);
        re+=nums[i];
    }
    // printf("\n");
    return re;
}

void numArrayFree(NumArray* obj) {
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */