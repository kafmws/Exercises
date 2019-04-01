int num[100]={0,1,2,3,5,8};

int climbStairs(int n) {
    if(num[n]!=0)return num[n];
    num[n-1] = climbStairs(n-1);
    num[n-2] = climbStairs(n-2);
    return num[n-1]+num[n-2];
}