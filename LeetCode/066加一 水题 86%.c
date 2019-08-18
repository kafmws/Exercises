/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    *returnSize = digitsSize;
    if(digitsSize==0){*returnSize = 1;int *res = malloc(sizeof(int));res[0]=1;return res;}
    if(digits[digitsSize-1]<9){digits[digitsSize-1]++; return digits;}
    int t = 1;
    digits[digitsSize-1] =  0;
    for(int i = digitsSize - 2;t&&i>=0;i--){
        t += digits[i];
        digits[i] = t%10;
        t /= 10;
    }
    if(t){
        int *res = malloc(sizeof(int)*(digitsSize + 1));
        res[0] = 1;
        for(int i = 0;i<digitsSize;i++){
            res[i+1] = digits[i];
        }
        *returnSize = digitsSize + 1;
        return res;
    }else return digits;
}

