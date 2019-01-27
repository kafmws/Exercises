bool isPalindrome(int x) {
    if(x<0)
        return false;
    char num[10000];
    sprintf(num,"%d",x);
    int len = strlen(num);
    for(int i = 0;i<len/2;i++){
        if(num[i]!=num[len-i-1])
            return false;
    }
    return true;
}