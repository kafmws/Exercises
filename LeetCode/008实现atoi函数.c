int myAtoi(char* str) {
    int i = 0;
    int flag = 1;
    while(str[i]==' ')
        i++;
    if(str[i]=='-')
        flag = -1, i++;
    else if(str[i]=='+')
        i++;
    else if(str[i]<'0'||str[i]>'9')
        return 0;
    while(str[i]=='0')
        i++;
    //数字开始
    char num[1000]={0};
    int cnt = 0;
    int re = 0;
    while(str[i]>='0'&&str[i]<='9'){
        num[cnt++] = str[i++];
        if(cnt>10){
            re = flag==1?2147483647:-2147483648;
            break;
        }
    }
    num[cnt]=0;
    if(cnt==10){
        puts(num);
        if(flag==1&&strcmp(num,"2147483647")>0)
            re = 2147483647;
        else if(flag==-1&&strcmp(num,"2147483648")>0)
            re = -2147483648;
    }
    if(re == 0){
        for(int i = cnt-1;i>=0;i--){
            re+=(num[i]-'0')*pow(10,cnt-i-1);
            //printf("%d ",re);
        }
        re*=flag;
    }
    return re;
}