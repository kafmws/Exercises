int strStr(char* haystack, char* needle) {
    int lenth = strlen(haystack);
    int len = strlen(needle);
    if(len==0)return 0;
    if(lenth>=len){
        for(int begin = 0;begin<lenth;begin++){
            int i = begin;
            int j = 0;
            while(j<len&&haystack[i] == needle[j]){
                i++,j++;
            }
            if(j==len)return begin;
        }
    }
    return -1;
}