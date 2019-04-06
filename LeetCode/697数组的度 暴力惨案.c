void put(int cnt[][2], int obj, int *size, int *maxTimes){
    for(int i = 0;i<*size; i++){
        if(cnt[i][0] == obj){
            cnt[i][1]++;
            if(cnt[i][1]>*maxTimes){
                *maxTimes = cnt[i][1];
            }
            return;
        }
    }
    cnt[*size][0] = obj;
    cnt[*size][1] = 1;
    (*size)++;
}

int findShortestSubArray(int* nums, int numsSize) {
    //找到出现次数最多的数
    //找到第一次出现和最后一次出现
    if(numsSize==1)return 1;
    int cnt[50000][2] = {0};
    int cntSize = 0;
    int maxTimes = 1;
    memcpy(cnt,nums,numsSize*4);
    for(int i = 0;i<numsSize;i++){
        put(cnt, nums[i], &cntSize, &maxTimes);
    }
    int objs[500000]={0};
    int objCnt = 0;
    for(int i = 0;i<cntSize; i++){
        if(cnt[i][1] == maxTimes){
            objs[objCnt++] = cnt[i][0];
        }
    }
    int result = 0x7fffffff;
    for(int i = 0;i<objCnt;i++){
        int begin = 0,end = numsSize - 1;
        while(nums[begin]!=objs[i])begin++;
        while(nums[end]!=objs[i])end--;
        if((end-begin+1)<result)result = end-begin+1;
    }
    // printf("max = %d begin = %d end = %d", max, begin, end);
    return result;
}