#include<stdio.h>
#include<string.h>

int n, k;
char num[305] = {0};
char result[305] = {0};
int index = 0;
int cnt = 0;
int len;

void select(int border){//��[index,border)��ѡ����Сֵ �����±� 
	//num[index]Ϊ0ʱһ�����ǵ�һλ �˴������ж� 
	for(int i = index; i<border; i++){
		if(num[i]<num[index]){
//			if(cnt==0){
//				if(num[i]=='0'&&len-k!=1)continue;//��һλ��Ϊ0 ����һλ
//			}
			index = i;
		}
	}
}

void process(char *num){
	len = strlen(num);
	int i = 0;
	while(num[i]=='0')i++;
	if(i){
		strcpy(num,num+i);
		len -= i;
	}
}

int main() {
//	scanf("%d%d",&n,&k);
//	sprintf(num,"%d",n);
	scanf("%s%d",num,&k); 
	process(num);
	for(int i = 1;i<=len-k;i++){
		select(k+i);
		result[cnt++] = num[index];//ѡ���i����
		index++;
	}
	if(strlen(result)>1)process(result);
	printf("%s",result);
	return 0;
}
