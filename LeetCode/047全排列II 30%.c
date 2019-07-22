//https://leetcode-cn.com/problems/permutations-ii/submissions/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int *nums, int i, int j) {
	int k = nums[i];
	nums[i] = nums[j];
	nums[j] = k;
}

void re(int *nums, int i, int **res, int border, int *cnt) {
	if (i >= border) {
        for(int j = 0;j<*cnt;j++){
            int flag = 1;//标记是否相同
            for(int k = 0;k<border;k++){
                if(nums[k]!=res[j][k]){
                    flag = 0;break;
                }
            }
            if(flag)return;
        }
		int *one = malloc(sizeof(int)*border);
		for (int j = 0; j < border; j++) {
			one[j] = nums[j];
		}
		res[(*cnt)++] = one;
		return;
	}
	for (int j = i; j < border; j++) {
        if (nums[i] == nums[j]&&i!=j) {
			continue;
		}
		swap(nums, i, j);
		re(nums, i + 1, res, border, cnt);
		swap(nums, i, j);
	}
}

int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = 1;
	for (int i = 1; i <= numsSize; i++) {
		(*returnSize) *= i;
	}
	*returnColumnSizes = malloc(sizeof(int)*(*returnSize));
	for (int i = 0; i < *returnSize; i++) {
		(*returnColumnSizes)[i] = numsSize;
	}
	int **res = malloc(sizeof(int *)*(*returnSize));
	*returnSize = 0;
	re(nums, 0, res, numsSize, returnSize);
	return res;
}