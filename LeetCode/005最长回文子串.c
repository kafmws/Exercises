int isPalindrome(char *s, int len){
    //从后向前找，先找到的是最长的
    for(int i = len-1;i;i--){
        if(s[0]==s[i]){
            int flag = 1,j=1;
            while(j<=i/2){
                if(s[0+j]!=s[i-j]){
                    flag = 0;
                    break;
                }
                j++;
            }
            if(flag){
                //printf("re");
                return i+1;//返回值在s中可取到
            }
        }
    }
    return 1;
}


char* longestPalindrome(char* s) {
    int max = 0;//记录位数
    int index;//记录起始下标
    int len = strlen(s);
    for(int i = 0;i<len;i++){
        int t = isPalindrome(&s[i],len-i);
        //printf("%d ",t);
        if(max<=t){
            max = t;
            index = i;
        }
        if(len-i<max)
            break;
    }
    char *str = (char *)malloc(sizeof(char)*(max+1));
    strncpy(str,&s[index],max);
    str[max]=0;
    //puts(str);
    return str;
}