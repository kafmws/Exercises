void put(int *re,int i,int j){
    re[0] = i;
    re[1] = j;
}

int* twoSum(int* nums, int numsSize, int target) {
    int *re = (int *)malloc(sizeof(int)*2);
    for(int i = 0;i<numsSize;i++){
        for(int j = i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                put(re,i,j);
                goto out;
            } 
        }
    }
    out :
    return re;
}