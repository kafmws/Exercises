//https://leetcode-cn.com/problems/trapping-rain-water/submissions/
//由左向右，找到第一个比它高、齐平或其中最高的
int trap(int* height, int heightSize){
    if(heightSize<=2)return 0;
    int i = 0, j;
    while(i+1<heightSize&&height[i]<height[i+1])i++;
    int left = i, sum = 0;
    i++;
    while(i<heightSize){
        j = i;
        int min = -1, minIndex = 0;
        while(j<heightSize&&height[j]<height[left]){
            if(height[j]>min){ min = height[j]; minIndex = j; }
            j++;
        }
        if(j==heightSize)i = minIndex;
        else i = j;
        //printf("%d %d\n",left, j);
        int smaller = height[left]<height[i]?height[left]:height[i];
        for(int j = left + 1;j<i;j++){
            sum += smaller - height[j];
        }
        left = i;
        i++;
    }
    return sum;
}