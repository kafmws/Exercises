/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *tail = head;
    while(l1&&l2){
        if(l1->val<=l2->val){
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }else{
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }
    if(l1){
        tail->next = l1;
    }
    if(l2){
        tail->next = l2;
    }
    tail = head->next;
    free(head);
    return tail;
}