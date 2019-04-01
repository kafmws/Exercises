int maxSubArray(int* nums, int numsSize) {
    int end = numsSize - 1;
    while(nums[end]<0&&end>0)end--;
    if(end==0)end = numsSize-1;
    int max = -0x7fffffff;
    for(int i = 0;i<=end;i++){
        int sum = 0;
        for(int j = i;j<=end;j++){
            sum+=nums[j];
            if(max<sum){
                max = sum;
            }
        }
    }
    return max;
}