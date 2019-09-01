int dietPlanPerformance(int* calories, int caloriesSize, int k, int lower, int upper){
    int res = 0;
    int cnt = 0;
    long long T = 0;
    int left = 0, right = 0;
    while(left<caloriesSize&&right<caloriesSize){
        T += calories[right++];
        cnt++;
        if(cnt==k){
        	left++;right = left;
            cnt = 0;
            if(T<lower)res--;
            else if(T>upper)res++;
            T = 0;
        }
    }
    return res;
}