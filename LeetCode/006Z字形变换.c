//找规律题目
char* convert(char* s, int numRows) {
    int len = strlen(s);
    char *str = (char *)malloc(sizeof(char)*(len+1));
    if(numRows==1)
        strcpy(str,s);
    else{
        int cnt = 0;
        for(int i = 1;i<=numRows;i++){
            int t = i;
            int judge = 0;
            //int gap = numRows*2-2*(t>(numRows+1)/2?numRows-i+1:t);//适用于奇数
            if(t==1||t==numRows){
                int gap = numRows*2-2*(t>(numRows+1)/2?numRows-i+1:t);//适用于奇数
                    while(t<=len){
                        str[cnt++] = s[t-1];
                        t += gap;
                    }
            }else{
                int gap_1 = numRows*2-2*t;
                int gap_2 = numRows*2-2*(numRows-i+1);
                
                //不需要
                //// if(t>(numRows+1)/2){
                ////     int tem = gap_1;
                ////     gap_1 = gap_2,gap_2 = tem;
                //// }
                //printf("%d %d",gap_1,gap_2);
                while(t<=len){
                    str[cnt++] = s[t-1];
                    t += judge%2==0?gap_1:gap_2;
                    judge++;
                }
            }
        }
        str[cnt]=0;
    }
    return str;
}