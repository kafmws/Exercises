bool isPerfectSquare(int num){
    unsigned i = 1;
	unsigned t = i*i;
	while(t<num){
		i++;
		t = i*i;
	}
	return t==num;
}