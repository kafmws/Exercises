int rangeBitwiseAnd(int m, int n){
	if(m==0)return 0;
    if(m==n)return m;
	int list[] = {0x80000000,0x40000000,0x20000000,0x10000000,0x8000000,0x4000000,
	0x2000000,0x1000000,0x800000,0x400000,0x200000,0x100000,0x80000,0x40000,0x20000,
	0x10000,0x8000,0x4000,0x2000,0x1000,0x800,0x400,0x200,0x100,0x80,0x40,0x20,0x10,
	0x8,0x4,0x2,0x1,};
	int bit = 0;
	for(int i = 0;i<32;i++){
		if((m&list[i])!=(n&list[i])){
			bit = i;
			break;
		}
	}
	int ones[] = {0,0x80000000,0xc0000000,0xe0000000,0xf0000000,0xf8000000,0xfc000000,
	0xfe000000,0xff000000,0xff800000,0xffc00000,0xffe00000,0xfff00000,0xfff80000,
	0xfffc0000,0xfffe0000,0xffff0000,0xffff8000,0xffffc000,0xffffe000,0xfffff000,
	0xfffff800,0xfffffc00,0xfffffe00,0xffffff00,0xffffff80,0xffffffc0,0xffffffe0,
	0xfffffff0,0xfffffff8,0xfffffffc,0xfffffffe,0xffffffff,};
    // printf("%d 0x%x",bit,ones[bit]);
	return m&ones[bit];
}

//6%
//int rangeBitwiseAnd(int m, int n) {
//	unsigned i = m+1;
//	while(i<=n) {
//		m &= i;
//		i++;
//		if(m==0)break;
//	}
//	return m;
//}

