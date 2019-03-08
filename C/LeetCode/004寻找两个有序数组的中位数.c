//要求算法的时间复杂度为 O(log(m + n))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int amount = nums1Size + nums2Size;
    int obj = (amount+1)/2;//中位数位置
    int cnt = 0;
    int num1 = 0,num2 = 0;
    int flag;//区分停下时数到哪个数组
    while(true){
        flag = 0;
        if(num1<nums1Size&&num2<nums2Size){
            if(nums1[num1]<nums2[num2]){
                num1++;
                flag=1;
            }else{
                num2++;
            }
        }
        else{//有数组走完
            if(num1<nums1Size){
                num1++;
                flag=1;
            }
            else
                num2++;
        }
        cnt++;
        if(cnt==obj)
            break;
    }//一定在中位数位置
    //printf("%d %d",nums1[num1],nums2[num2]);
    int before = flag?nums1[num1-1]:nums2[num2-1];
    //printf("%d",before);
    if(amount%2!=0)
        return before;
    else{
        //flag?num1++:num2++;已经++
        int latter;
        if(num1<nums1Size&&num2<nums2Size)
            latter = nums1[num1]<nums2[num2]?nums1[num1]:nums2[num2];
        else
            latter = num1<nums1Size?nums1[num1]:nums2[num2];
        //printf("%d %d\n",num1,num2);
        //printf("%d %d",before,latter);
        return (before+latter)/2.0;
    }
}