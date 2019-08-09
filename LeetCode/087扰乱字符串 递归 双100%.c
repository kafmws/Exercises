//void print(char *s, int len) {
//	for (int i = 0; i < len; i++) {
//		printf("%c", s[i]);
//	}
//	printf("\n");
//}

bool partition(char *s1, char *s2, int len, int *hash) {
	//print(s1, len); print(s2, len);
	if (strncmp(s1, s2, len) == 0)return true;
	int flag = 0;
	int border = len - 1;
	for (int i = 1; i <= border; i++) {
		memset(hash, 0, sizeof(int) * 127);
		for (int j = 0; j < i; j++) {
			hash[s1[j]]++;
			hash[s2[j]]--;
		}
		flag = 0;
		for (int j = 0; j < 127; j++) {
			if (hash[j]) {
				flag = 1; break;
			}
		}
		if (flag == 0) { /*printf("(1)在第%d个字符分隔\n", i);*/ if( partition(s1 + i, s2 + i, len - i, hash) && partition(s1, s2, i, hash)) return true; }
		int index = border;
		memset(hash, 0, sizeof(int) * 127);
		for (int j = 0; j < i; j++) {
			hash[s1[j]]++;
			hash[s2[index--]]--;
		}
		flag = 0;
		for (int j = 0; j < 127; j++) {
			if (hash[j]) {
				flag = 1; break;
			}
		}
		if (flag == 0) { /*printf("(2)在第%d个字符分隔\n", i);*/ if (partition(s1 + i, s2, len - i, hash) && partition(s1, s2 + index + 1, i, hash)) return true; }
	}
	return false;
}

bool isScramble(char * s1, char * s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2)return false;
	if (strcmp(s1, s2) == 0)return true;
	int hash[127] = { 0 };
	for (int i = 0; i < len1; i++) {
		hash[s1[i]]++;
		hash[s2[i]]--;
	}
	for (int i = 0; i < 127; i++) {
		if (hash[i])return false;
	}
	return partition(s1, s2, len1, hash);
}