int isPalindrome(char *s, int len){
    //�Ӻ���ǰ�ң����ҵ��������
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
                return i+1;//����ֵ��s�п�ȡ��
            }
        }
    }
    return 1;
}


char* longestPalindrome(char* s) {
    int max = 0;//��¼λ��
    int index;//��¼��ʼ�±�
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