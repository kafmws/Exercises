int getNumIndex(char *num, int m) {
	int i = 0;
	while (m != 0) {
		if (num[i++])m--;
	}
	return i - 1;
}

char * getPermutation(int n, int k) {
	//int base[] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320 };
	int basis[9] = { 40320, 5040, 720, 120, 24, 6, 2, 1 };
	int *base = basis;
	for (int i = n; i < 9; i++) { base++; }
	char num[] = { '1','2','3','4','5','6','7','8','9' };
	char *res = malloc(sizeof(char) + (n + 1));
    memset(res,0,sizeof(char) + (n + 1));
	int index = 0;//开始位数
	int t, m;//偏移量,当前可选第m小的数
	for (int i = 0; i < n; i++) {
		if (k == 1) {
			for (int j = 0; i < n; j++) {//最小序
				if (num[j])res[i++] = num[j];
			}
			break;
		}
		while (k < base[index])index++;
		while (i < index) {
			m = getNumIndex(num, 1);
			res[i++] = num[m];
			num[m] = 0;
		}
		t = k / base[index];
		k %= base[index];
		if (k == 0) {
			m = getNumIndex(num, t);
			res[i++] = num[m];
			num[m] = 0;
			for (int j = n - 1; i < n; j--) {//最大序
				if (num[j])res[i++] = num[j];
			}
			break;
		}
		m = getNumIndex(num, t + 1);
		res[i] = num[m];
		num[m] = 0;
	}
	return res;
}