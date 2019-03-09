void strrev(char *s, int len){
    for(int i = 0;i<len/2;i++){
        char c = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = c;
    }
}

int reverse(int x) {
    char num[25]={0};
    sprintf(num,"%d",x);
    char *str = num;
    if(str[0]=='-'||str[0]=='+')
        str++;
    int len = strlen(str);
    strrev(str, len);
    //printf("%d",len);
    //printf("%d",strcmp("2147483647","2147483648"));
    if(len==10){//ÅĞ¶ÏÒç³ö
        //puts(str);
        if((num[0]!='-'&&strcmp(str,"2147483647")>0)
           ||(num[0]=='-'&&strcmp(str,"2147483648")>0))
        return 0;
    }
    return atoi(num);
}