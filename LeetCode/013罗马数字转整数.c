int re(char c){
    int value;
    switch(c){
        case 'I':value=1;break;
        case 'V':value=5;break;
        case 'X':value=10;break;
        case 'L':value=50;break;
        case 'C':value=100;break;
        case 'D':value=500;break;
        case 'M':value=1000;break;
        default:break;
    }
    return value;
}

int romanToInt(char* s) {
    int len = strlen(s);
    int result = 0;
    for(int i = 0;i<len-1;i++){
        if(re(s[i])-re(s[i+1])<0)
            result -= re(s[i]);
        else
            result += re(s[i]);
    }
    result += re(s[len-1]);
    return result;
}