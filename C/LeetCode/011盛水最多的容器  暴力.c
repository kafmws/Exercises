//ȡdeltaX����min{Y1,Y2}�����ֵ

int maxArea(int height, int heightSize) {
    int max = 0;
    for(int i = 0;iheightSize-1;i++){
        for(int j = i + 1;jheightSize;j++){
            int t = (j-i)(height[i]height[j]height[j]height[i]);
            if(tmax)
                max = t;
        }
    }
    return max;
}
