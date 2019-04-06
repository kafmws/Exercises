int maxProfit(int* prices, int pricesSize) {
    if(pricesSize<=0)return 0;
    int min=prices[0],max=prices[pricesSize - 1];
    // int minIndex = 0, maxIndex = pricesSize - 1;
    // int i = minIndex + 1, j = maxIndex;
    int i = 1, j = pricesSize - 2;
    while(i<=j){
        if(prices[i]<min){
            min = prices[i];
            // minIndex = i;
        }
        if(prices[j]>max){
            max = prices[j];
            // maxIndex = j;
        }
        i++,j--;
    }
    int res = max - min;
    return res>0?res:0;
}