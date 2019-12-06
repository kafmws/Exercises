//https://leetcode-cn.com/problems/merge-sorted-array/submissions/
void reverse(int *num, int begin, int end){
    int t;
    while(begin<end){
        t = num[begin];
        num[begin] = num[end];
        num[end] = t;
        begin++;end--;
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0, j = m, mn = m + n - 1, border = m - 1;
    memcpy(nums1+m,nums2,sizeof(int)*n);
    while(border<mn){
        while(i<j&&nums1[i]<=nums1[j])i++;
        if(i == j)break;
        while(j<=mn&&nums1[i]>=nums1[j])j++;
        reverse(nums1,i,border);
        reverse(nums1,border+1,j-1);
        reverse(nums1,i,j-1);
        border = j - 1;
    }
}