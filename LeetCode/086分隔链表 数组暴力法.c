struct ListNode* partition(struct ListNode* head, int x) {
	int left[1000]= {0};
	int right[1000]= {0};
	int lCnt = 0, rCnt = 0;
	struct ListNode* p = head;
	while(p) {
		if(p->val<x)
			left[lCnt++] = p->val;
		else
			right[rCnt++] = p->val;
		p = p->next;
	}
	p = head;
	int i = 0;
	while(i<lCnt) {
		p->val = left[i++];
		p = p->next;
	}
	i = 0;
	while(i<rCnt) {
		p->val = right[i++];
		p = p->next;
	}
	return head;
}