int evalRPN(char ** tokens, int tokensSize) {
	int stack[100000] = {0};
	int top = 0;
	int cnt = 0;
	while(cnt<tokensSize) {
		switch(tokens[cnt][0]) {
			case '*':stack[top-2] = stack[top-2]*stack[top-1];top--;break;
			case '/':stack[top-2] = stack[top-2]/stack[top-1];top--;break;
			case '+':
				if(tokens[cnt][1]){
					stack[top++] = atoi(tokens[cnt]);
				}else{
					stack[top-2] = stack[top-2]+stack[top-1];top--;
				}
			break;
			case '-':
				if(tokens[cnt][1]){
					stack[top++] = atoi(tokens[cnt]);
				}else{
					stack[top-2] = stack[top-2]-stack[top-1];top--;
				}break;
			default:
				stack[top++] = atoi(tokens[cnt]);
		}
		cnt++;
	}
	return stack[0];
}