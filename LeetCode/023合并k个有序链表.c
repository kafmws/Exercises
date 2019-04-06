/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void checkSize(struct ListNode** lists, int *listsSize){//将listsSize规范化为可用范围
    for(int i = 0;i<*listsSize;i++){
        while(*listsSize>0&&lists[(*listsSize)-1]==NULL)(*listsSize)--;//找到当前非NULL
        if((*listsSize)==0)return;
        if(lists[i]==NULL){
            lists[i] = lists[(*listsSize)-1];
            (*listsSize)--;
        }
    }
}

struct ListNode* findCurrentMin(struct ListNode** lists, int *listsSize){
    if(*listsSize==1){
        (*listsSize)--;
        return lists[0];
    }
    int index;
    int min  = 0x7fffffff;
    for(int i = 0;i<*listsSize;i++){
        if(lists[i]->val<min){
            min = lists[i]->val;
            index = i;
        }
    }//找到当前最小
    struct ListNode* res = lists[index];
    lists[index] = lists[index]->next;//后移
    if(lists[index]==NULL){//这条链结束
        lists[index] = lists[(*listsSize) - 1];
        (*listsSize)--;
    }//缩短范围
    return res;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    checkSize(lists, &listsSize);
    printf("%d",listsSize);
    if(listsSize==0)return NULL;
    if(listsSize==1)return lists[0];
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *tail = head;
    // while(!isFinished(lists, &listsSize)){
    while(listsSize){
        tail->next = findCurrentMin(lists, &listsSize);
        tail = tail->next;
    }
    tail = head->next;
    free(head);
    return tail;
}