int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize == 0)return 0;
    int cnt[10000];
    for(int i = 0;i<numsSize;i++){
        cnt[i] = 1;
    }
    int max = 1;
    for(int i = 1;i<numsSize;i++){
        for(int j = 0;j<i;j++){
            if(nums[i]>nums[j]&&cnt[i]<=cnt[j]){
                cnt[i] = cnt[j]+1;
                if(cnt[i]>max){
                    max = cnt[i];
                }
            }
        }
    }
    return max;
}