/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int searchRight(int *nums, int numsSize, int target){//最右
    if(numsSize<=0)return -1;
    int left = 0;
    int right = numsSize-1;
    int mid = (left+right)/2;
    int re = -1;
    while(left<=right){
        if(nums[mid]==target){
            re = mid;
            left = mid+1;
        }else if(nums[mid]<target){
            left = mid+1;
        }else{
            right = mid-1;
        }
        mid = (left+right)/2;
    }
    return re;
}

int searchLeft(int *nums, int numsSize, int target){//最左
    int left = 0;
    int right = numsSize-1;
    int mid = (left+right)/2;
    int re = -1;
    while(left<=right){
        if(nums[mid]==target){
            re = mid;
            right = mid-1;
        }else if(nums[mid]<target){
            left = mid+1;
        }else{
            right = mid-1;
        }
        mid = (left+right)/2;
    }
    return re;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *num = (int *)malloc(sizeof(int)*2);
    num[0] = num[1] = -1;
    if(numsSize==0)return num;
    num[0] = searchLeft(nums,numsSize,target);
    if(num[0]!=-1){//如果有target
        num[1] = searchRight(&nums[num[0]]+1,numsSize-num[0]-1,target)+num[0]+1;
        if(num[1]==-1){num[1]=num[0];}
    }
    return num;
}