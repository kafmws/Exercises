/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode* pre = NULL;
    struct ListNode* flag = head;
    while(flag&&flag->val<x){
        pre = flag;
        flag = flag->next;
    }
    struct ListNode* ppre = flag;
    struct ListNode* p = NULL;
    if(flag)
        p = flag->next;
    while(p){
        if(p->val<x){
            ppre->next = p->next;
            p->next = flag;
            if(pre)pre->next = p;
            else head = p;
            pre = p;
            p = ppre->next;
        }else{
            ppre = p;
            p = p->next;
        }
    }
    return head;
}