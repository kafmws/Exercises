bool isValid(char * s) {
	char *st = s;
	int top = 0;
	int cmp = 0;
	while(*st) {
		if(top==0) {
			if((*st)==')'||(*st)==']'||(*st)=='}')return 0;
			cmp = top;
			s[top++] = *st;
		} else {
			if((*st)-s[cmp]==2||(*st)-s[cmp]==1) {
				top--;
				cmp--;
			} else {
				cmp = top;
				s[top++] = *st;
			}
		}
		st++;
	}
	return 0==top;
}
