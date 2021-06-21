
 // Definition for singly-linked list.
 #include <stdlib.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };



struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *lastremove = NULL;
    struct ListNode *newhead = NULL, *newend = NULL;
    struct ListNode *p = head, *q = NULL;

    while(p){
        q = p->next;
        while (q && q->val == p->val ||
            lastremove && lastremove->val == p->val){
            p->next = NULL;
            lastremove = p;
            p = q;
            if (p == NULL)
                break;
            q = p->next;
        }
        if (newhead == NULL)
            newhead = p;
        if (newhead == NULL)
            return;
            
        if (newend == NULL){
            newend = newhead;
            newend->next = NULL;
        }else{
            newend->next = p;
            newend = newend->next;
            newend->next = NULL;
        }
        p = q;
    }

    return newhead;
}