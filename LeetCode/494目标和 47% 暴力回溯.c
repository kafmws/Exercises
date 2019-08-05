void re(int* left, int *nums, int i, int numsSize, int sum, int S, int *cnt){
	if(i==numsSize){
		if(sum==S)(*cnt)++;
		return;
	}
	if(sum+left[i]<S)return;
	re(left,nums,i+1,numsSize,sum+nums[i],S,cnt);
	if(sum-left[i]>S)return;
	re(left,nums,i+1,numsSize,sum-nums[i],S,cnt);
} 

int findTargetSumWays(int* nums, int numsSize, int S){
	int cnt = 0;
	int left[21]={0};
	for(int i = numsSize - 1;i>=0;i--){
		left[i] += left[i+1] + nums[i];
	} 
	re(left,nums,0,numsSize,0,S,&cnt);
	return cnt;
}

