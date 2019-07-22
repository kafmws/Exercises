//https://leetcode-cn.com/problems/permutations/submissions/
void swap(int *nums, int i, int j) {
	int k = nums[i];
	nums[i] = nums[j];
	nums[j] = k;
}

void re(int *nums, int i, int **res, int border, int *cnt) {
	if (i >= border) {
		int *one = malloc(sizeof(int)*border);
		for (int j = 0; j < border; j++) {
			one[j] = nums[j];
		}
		res[(*cnt)++] = one;
		return;
	}
	for (int j = i; j < border; j++) {
		swap(nums, i, j);
		re(nums, i + 1, res, border, cnt);
		swap(nums, i, j);
	}
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 1;
	for (int i = 1; i <= numsSize; i++) {
		(*returnSize) *= i;
	}
	*returnColumnSizes = malloc(sizeof(int)*(*returnSize));
	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = numsSize;
	}
	int **res = malloc(sizeof(int *)*(*returnSize));
	int cnt = 0;
	re(nums, 0, res, numsSize, &cnt);
	return res;
}