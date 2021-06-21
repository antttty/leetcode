
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* smallstart = nullptr,  *smallend = nullptr;
        ListNode* bigstart = nullptr, *bigend = nullptr;
        ListNode* p = head, *q = nullptr;

        while (p){
            q = p->next;
            p->next = nullptr;
            if (smallstart == nullptr && p->val < x){
                smallend = smallstart = p;
                smallend->next = nullptr;
            }else if (bigstart == nullptr && p->val >= x){
                bigend = bigstart = p;
                bigend->next = nullptr;
            }else if (p->val >= x && bigend){
                bigend->next = p;
                bigend = bigend->next;
            }else if (p->val < x && smallend){
                smallend->next = p;
                smallend = smallend->next;
            }
            p = q;
        }
        if (smallend)
            smallend->next = bigstart;
        return smallstart;
    }

    int main(){
        ListNode node1(2), node2(1);
        node1.next = &node2;
        ListNode *p = &node1;
        partition(p, 2);
        return 0;
    }