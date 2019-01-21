int calculate(char *s, int *len, int lenth, int index){
    char flag[256] = {0};
    int i = index;
    for(;i<lenth;i++){
        if(flag[s[i]]==0)
            flag[s[i]]++;
        else{
            break;
        }
    }
    return i - index;
}

int lengthOfLongestSubstring(char* s) {
    int lenth = strlen(s);
    int max = 0;
    int len[100000]={0};
    for(int i = 0;i<lenth;i++){
        int t = calculate(s,len,lenth,i);
        if(t>max)
            max = t;
        if(lenth-i<max)
            break;
    }
    return max;
}