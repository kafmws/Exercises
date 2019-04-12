/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    *returnSize = num+1;
    int *array = (int *)malloc(sizeof(int)**returnSize);
    array[0] = 0;
    const double eps = 1e-10;
    const double log102 = log10(2);
    int latestInt = 1;
    for(int i = 1;i<*returnSize;i++){
        int lastBit = i&0x1;
        if(lastBit){//奇数
            array[i] = array[i-1]+1;
        }else{
            double tem = log10(i)/log102;
            if((tem-(int)tem)<eps){//2的整数次方
                array[i] = 1;
                latestInt = i;
            }else{//判断是否由几个2的整数次方组成
                array[i] = array[latestInt]+array[i-latestInt];
            }
        }
    }
    return array;
}