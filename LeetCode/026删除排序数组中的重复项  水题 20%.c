int removeDuplicates(int* nums, int numsSize){
    if(numsSize <= 1)return numsSize;
    // if(numsSize<=3)return 1+(nums[0]!=nums[1])+(nums[1]!=nums[2]);
    int cnt = (nums[0]!=nums[1]);//1+
    for(int i = cnt+1;i<numsSize;i++){
        if(nums[i]!=nums[cnt])nums[++cnt] = nums[i];
    }
    return cnt+1;
}