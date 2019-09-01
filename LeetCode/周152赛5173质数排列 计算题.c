int numPrimeArrangements(int n) {
	if (n <= 2)return 1;
	int primes[26] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97, };
	int primeCnt = 0;//[0, primeCnt)
	while (primeCnt < 26 && primes[primeCnt] <= n)primeCnt++;
	if(primeCnt==26)primeCnt--;
	int NonPrime = n - primeCnt;
	printf("primeCnt=%d,NonPrime=%d\n", primeCnt, NonPrime);
	int smallone = primeCnt > NonPrime ? NonPrime : primeCnt;
	int bigone = primeCnt < NonPrime ? NonPrime : primeCnt;
	int i = 2;
	long long a = 1;
	while (i <= smallone) { a *= i; while (a >= 1000000007)a -= 1000000007; i++; }
	long long b = a;
	while (i <= bigone) {
		b *= i;
		while (b >= 1000000007)b -= 1000000007;
		i++;
	}
	long long res = a * b;
	printf("a=%lld,b=%lld\n", a, b);
	return res % 1000000007;
}