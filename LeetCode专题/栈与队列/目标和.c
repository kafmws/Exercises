#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

char * addBinary(char * a, char * b){
    int lena = strlen(a);
    int lenb = strlen(b);
    int longlen = lena>lenb?lena:lenb;
    int shortlen = lena<lenb?lena:lenb;
    char tem[100000] = {0};
    int len = 0;
    int t = 0;
    while(shortlen>0){
        if(a[len]==b[len]){// 0 0 or 1 1
            tem[len]=t;
            t = a[len]=='1';
        }
        len++;
        shortlen--;
    }
    puts(tem);
    if(t){
        while(len<lena){  
            t += a[len];
            tem[len++] = t&1;
            t /= 2;
        }
        while(len<lenb){  
            t += b[len];
            tem[len++] = t&1;
            t /= 2;
        }
    }else{
         while(len<lena){
            tem[len] = a[len];
            len++;
        }
        while(len<lenb){
            tem[len] = b[len];
            len++;
        }
    }
    tem[len]=0;
    char *res = malloc(sizeof(char)*(len+1));
    strcpy(res,tem);
    return res;
}

int main() {
	char a[110] = { 0 };
	char b[110] = { 0 };
	while (1) {
		scanf("%s %s", a, b);
		char *res = addBinary(a, b);
		printf("%s\n", res);
	}
	return 0;
}
