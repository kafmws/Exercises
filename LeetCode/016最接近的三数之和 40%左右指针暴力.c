int cmp(const void *a, const void *b) {
    return *((int *)a) - *((int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int offset = 0x7fffffff;
    int leftBase = 0, rightBase = numsSize - 1;
    int left, right, mid, tem, toff;
    while (leftBase + 1 < numsSize) {
        while (leftBase + 1 < rightBase) {
            left = leftBase;
            right = rightBase--;
            //if(left==1)
            //printf("%d %d\n", left, right);
            mid = (left + right) >> 1;
            tem = nums[left] + nums[right];
            if (tem + nums[mid] > target) {
                do {
                    mid--;
                } while (tem + nums[mid] > target&&mid > left);
                tem -= target;
                if (mid != left) {
                    toff = tem + nums[mid];
                    if (abs(toff) < abs(offset)) {
                        offset = toff;
                    }
                }
                toff = tem + nums[mid + 1];
                if (abs(toff) < abs(offset)) {
                    offset = toff;
                }
            }
            else if (tem + nums[mid] < target) {
                do {
                    mid++;
                } while (tem + nums[mid] < target&&mid < right);
                tem -= target;
                if (mid != right) {
                    toff = tem + nums[mid];
                    if (abs(toff) < abs(offset)) {
                        offset = toff;
                    }
                }
                toff = tem + nums[mid - 1];
                if (abs(toff) < abs(offset)) {
                    offset = toff;
                }
            }
            else return target;
            if (offset == 0)return target;
        }
        leftBase++;
        rightBase = numsSize - 1;
    }
    return target + offset;
}
