char * addBinary(char * a, char * b) {
	int lena = strlen(a);
	int lenb = strlen(b);
	char tem[100000] = { 0 };
	int len = 0;
	int t = '0';
	int ta = lena - 1, tb = lenb - 1;
	while (ta >= 0 && tb >= 0) {
		if (a[ta] == b[tb]) {// 0 0 or 1 1
			tem[len++] = t;
			t = a[ta];
		}
		else {
			tem[len++] = t=='1' ? '0' : '1';
		}
		ta--; tb--;
	}
		while (t == '1'&&len < lena) {
			tem[len] = t == a[ta] ? '0' : '1';
			t = t == a[ta] ? '1' : '0';
			len++; ta--;
		}
		while (t == '1'&&len < lenb) {
			tem[len] = t == b[tb] ? '0' : '1';
			t = t == b[tb] ? '1' : '0';
			len++; tb--;
		}
		if (t == '1')tem[len++] = '1';
		else{
		while (len < lena) {
			tem[len] = a[ta];
			len++; ta--;
		}
		while (len < lenb) {
			tem[len] = b[tb];
			len++; tb--;
		}
		}
	tem[len] = 0;
	char *res = malloc(sizeof(char)*(len + 1));
	int cnt = len-1;
	for (int i = 0; i < len; i++) {
		res[cnt--] = tem[i];
	}
	res[len] = 0;
	return res;
}