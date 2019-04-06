int multiply(int start, int end){
    int re = 1;
    for(int i = start;i>end;i--){
        re*=i;
    }
    return re;
}

int countNumbersWithUniqueDigits(int n) {
    if(n==0)return 1;
    if(n==1)return 10;
    return multiply(10,10-n)-multiply(9,9-n+1)
        +countNumbersWithUniqueDigits(n-1);
}