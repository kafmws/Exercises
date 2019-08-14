int removeElement(int* nums, int numsSize, int val){
    numsSize--;
    for(int i = 0;i<=numsSize;i++){
        if(nums[i]==val){
            while(numsSize>i&&nums[numsSize]==val)numsSize--;
            nums[i] = nums[numsSize--];
        }
    }
    return numsSize+1;
}