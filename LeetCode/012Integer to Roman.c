//  I1  V5  X10 L50 C100    D500    M1000
void fill(int weight, int value, char *re, int *cnt){//weight单位
    char weights[] = {' ','I','X','C','M'};
    char fives[] = {' ','V','L','D'}; 
    value -= '0';
    switch(value){
        case 0:
        case 1:
        case 2:
        case 3:
            for(int i = 0;i<value;i++){
                re[(*cnt)++]=weights[weight];
            }
            break;
        case 4:re[(*cnt)++]=weights[weight];
        case 5:re[(*cnt)++]=fives[weight];break;
        case 6:
        case 7:
        case 8:re[(*cnt)++]=fives[weight];
            for(int i=0;i<value-5;i++)
                re[(*cnt)++]=weights[weight];
            break;
        case 9:re[(*cnt)++]=weights[weight];
            re[(*cnt)++]=weights[weight+1];break;
    }
}

char* intToRoman(int num) {
    char str[5]={0};
    sprintf(str,"%d",num);
    int len = strlen(str);
    char *re = (char *)malloc(sizeof(char)*20);
    memset(re,0,sizeof(char)*20);
    int cnt = 0;
    for(int i = 0;i<len;i++){//从高位开始
        fill(len-i,str[i],re,&cnt);//位,值,字符串,计数器
    }
    return re;
}