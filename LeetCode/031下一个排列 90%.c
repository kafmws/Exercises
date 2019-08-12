int cmp(const void *a, const void *b){
	return (*(int *)a)-(*(int *)b);
}

//从后向前找到非升序的最短序列，改造该序列
void nextPermutation(int* nums, int numsSize){
	if(numsSize <= 1)return;
	int i = numsSize-1;//逆序升序的最后一个数 
	for(;i>0;i--){
		if(nums[i]>nums[i-1])break;
	}
	if(i==0){//最大降序 
		qsort(nums,numsSize,sizeof(int),cmp);
		return;
	}
	int index = i;
	for(int j = i+1;j<numsSize;j++){
		if(nums[j]>nums[i-1]&&nums[j]<nums[index])index = j;
	}
	int t = nums[i-1];
	nums[i-1] = nums[index];
	nums[index] = t;
	qsort(&nums[i],numsSize-i,sizeof(int),cmp);
}

