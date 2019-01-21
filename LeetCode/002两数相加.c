/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int addNode(struct ListNode** tail, struct ListNode* l1, struct ListNode* l2, int t){
    struct ListNode *l = (struct ListNode*)malloc(sizeof(struct ListNode));
    int tem = l2==NULL?l1->val+t:l1->val+l2->val+t;
    l->val = tem%10;
    l->next = (*tail)->next;
    (*tail)->next = l;
    *tail = l;
    return tem/10;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *tail = head;
    int t = 0;
    while(l1&&l2){
        t = addNode(&tail,l1,l2,t);
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1){
        t = addNode(&tail,l1,NULL,t);
        l1 = l1->next;
    }
    while(l2){
        t = addNode(&tail,l2,NULL,t);
        l2 = l2->next;
    }
    if(t){
        struct ListNode *l = (struct ListNode*)malloc(sizeof(struct ListNode));
        l->val = t;
        l->next = tail->next;
        tail->next = l;
    }
    struct ListNode *dead = head;
    head = head->next;
    free(dead);
    return head;
}
