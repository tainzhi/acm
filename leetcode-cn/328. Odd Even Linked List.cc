/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        auto odd = new ListNode(0), even = new ListNode(0);
        ListNode  *o = odd, *e = even, *p = head;
        int cnt = 1;
        while (p != NULL) {
            if ((cnt)%2 == 1)  {
                o->next = p;
                o = o->next;
            } else {
                e->next = p;
                e = e->next;
            }
            cnt++;
            p = p->next;
        }
        o->next = even->next;
        e->next = NULL;
        head = odd->next;
        delete even, odd;
        return head;
    }
};