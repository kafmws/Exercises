/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(n==0)return head;
    int cnt = 0;
    struct ListNode* p = head;
    struct ListNode* dead = NULL;
    while(p){
        cnt++;
        p = p->next;
    }
    if(cnt==n){
        dead = head;
        head = head->next;
        free(dead);
        return head;
    }
    p = head;
    for(int i = cnt - n;i>1;i--,p=p->next);
    dead = p->next;
    p->next = dead->next;
    free(dead);
    return head;
}