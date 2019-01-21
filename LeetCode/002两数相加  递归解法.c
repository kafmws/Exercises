/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void addNode(struct ListNode *tail, struct ListNode *l1, struct ListNode *l2, int t){
    struct ListNode *l = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(l1!=NULL){
        t+=l1->val;
        l1=l1->next;
    }
    if(l2!=NULL){
        t+=l2->val;
        l2=l2->next;
    }
    l->val = t%10;
    l->next = tail->next;
    tail->next = l;
    if(l1!=NULL||l2!=NULL||t/10)//处理进位
        addNode(l,l1,l2,t/10);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    addNode(head,l1,l2,0);
    struct ListNode* dead = head;
    head = head->next;
    free(dead);
    return head;
}