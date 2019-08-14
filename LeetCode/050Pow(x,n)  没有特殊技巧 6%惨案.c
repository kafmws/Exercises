double myPow(double x, int n){
    if(n==0||x==1)return 1.0;
    if(x==0)return 0;
    if(x==-1){ return (n&1)?-1:1; }
    double re = 1;
    unsigned nn;
    int flag = n>0?1:-1;
    if(n==-2147483648)nn = 2147483648;
    else nn = abs(n);
    for(int i = 1;i<=nn;i++){
        re *= x;
        if(fpclassify(re)==FP_ZERO||fpclassify(re)==FP_INFINITE)break;
    }
    re = flag==1?re:1/re;
    return re;
}
