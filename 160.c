#include <stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int m = 0, n = 0;
    struct ListNode *cura = headA, *curb = headB;
    while(cura){
        m++;
        cura = cura->next;
    }

    while(curb){
        n++;
        curb = curb->next;
    }

    int span = 0;
    cura = headA;
    curb = headB;

    if (m > n){
        span = m - n;
        while(span-- > 0){
            cura = cura->next;
        }
    }else if (m < n){
        span = n - m;
        while(span-- > 0){
            curb = curb->next;
        } 
    }

    while(cura && curb){
        if (cura == curb)
            return curb;
        cura = cura->next;
        curb = curb->next;
    }
    return NULL;
}