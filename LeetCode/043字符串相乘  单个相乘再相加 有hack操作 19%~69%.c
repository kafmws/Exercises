//用ch乘以num1，结果由res[resend]开始向前存放 //返回resstart ,[resstart, resend]
int mult(char *res, int resend, char *num1, int len1, int ch) {
	int t = 0;//表示进位 
	for (len1 -= 1; len1 >= 0; len1--) {
		res[resend--] = (ch*num1[len1] + t) % 10;
		t = (ch*num1[len1] + t) / 10;
	}
	if (t)res[resend] = t;
	else resend++;
	return resend;
}

//从res[resend]、tem[temend]开始相加，到tem[tembegin] ,存储至res 
void addto(char *tem, int tembegin, int temend, char *res, int resend) {
	int t = 0, temp;
	for (int i = temend; i >= tembegin; i--) {
		temp = res[resend] + tem[i] + t;
		res[resend] = temp % 10;
		t = temp / 10;
		resend--;
	}
	if (t)res[resend] = t;
}

char * multiply(char * num1, char * num2) {
	int len1 = 0, len2 = 0;
	for (; num1[len1]; len1++) {//转为数字，并记录长度 
		num1[len1] -= '0';
	}
	for (; num2[len2]; len2++) {//转为数字，并记录长度 
		num2[len2] -= '0';
	}
	char *res = malloc(sizeof(char)*(len1 + len2 + 1));
	memset(res, 0, sizeof(char)*(len1 + len2 + 1));
	if (num1[0] == 0 || num2[0] == 0) { res[0] = '0'; return res; }
	char *tem = malloc(sizeof(char)*(len1 + 2));//用num2的每一位去乘num1
	memset(res, 0, sizeof(char)*(len1 + 2));
	int tembegin;
	int temend = len1 + 1;//[tembegin,temend]
	int resend = len1 + len2 - 1;
	for (int i = len2 - 1; i >= 0; i--) {//用num2[i]乘以 num1,结果放在tem,从尾部开始
		tembegin = mult(tem, temend, num1, len1, num2[i]);
		
		/*printf("tem: ");
		for (int j = tembegin; j <= temend; j++)printf("%d", tem[j]);
		printf("\n");*/
		
		addto(tem, tembegin, temend, res, resend);
		resend--;

		/*printf("res: ");
		for (int j = 0; j <= len1+len2; j++)printf("%d", res[j]);
		printf("\n");*/

	}
	for (int i = 0; i < len1 + len2; i++) {
		res[i] += '0';
	}
	while (*res == '0')res++;
	return res;
}