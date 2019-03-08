#include<iostream>
#include<string.h>
using namespace std;
void f(char *s,char *t){
	int i,j,s1;
	s1 = strlen(s);
	for(i = 0;i<s1;i++)
	t[i]=s[i];
	for(i = 0;i<s1;i+=2,j++){
		t[s1+j]=s[s1-i-1];
		t[2*s1]=0;
	}
}

int main(){
	char s[10],t[20];
	cin>>s;
	f(s,t);
	cout<<t<<endl;
	return 0;
}
