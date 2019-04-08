struct ListNode* rotate(struct ListNode* begin, int k){//从begin开始,将前k个结点数据域翻转 返回第k+1个结点
    struct ListNode* p = begin;
    struct ListNode* re = NULL;
    int num[1000]={0};
    printf("录入");
    for(int i = 0;i<k;i++,p=p->next){
        num[i] = p->val;
    }
    re = p;
    int start = 0, end = k-1;
    while(start<end){
        int t = num[start];
        num[start] = num[end];
        num[end] = t;
        start++,end--;
    }
    p = begin;
    for(int i = 0;i<k;i++,p=p->next){
        p->val = num[i];
    }
    return re;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    struct ListNode* p = head;
    int cnt = 0;
    while(p){cnt++;p = p->next;}
    if(cnt==0)return head;
    k%=cnt;
    if(k){
        p = rotate(head,cnt-k);
        rotate(p,k);
        rotate(head,cnt);
    }
    return head;
}