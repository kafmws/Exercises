char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize<=0)
        return "";
    if(strsSize==1)
        return strs[0];
    int i = 0;
    int flag = 1;
    for(;flag&&i<strlen(strs[0]);i++){
        for(int j = 1;j<strsSize;j++){//δ���i�Ƿ񳬹�ÿ��string�ĳ��ȣ���������C������˵�ǰ�ȫ��
            if(strs[j][i]!=strs[0][i]){
                flag = 0;
                break;
            }
        }
    }
    if(i==0){
        return "";
    }
    char *re = (char *)malloc(sizeof(char)*i+1);
    memset(re,0,sizeof(char)*i+1);
    for(int j = 0;j<i-1;j++){
        re[j] = strs[0][j];
    }
        re[i-1]=flag?strs[0][i-1]:0;
    //printf("emmm\\%s%d",re,i);
    return re;
}