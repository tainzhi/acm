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
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
        {
            return false;
        }
        ListNode *p = head, *pp = head->next;
        while (pp != nullptr && pp->next != nullptr && p != nullptr)  {
            if (p == pp) {
                return true;
            }
            p = p->next;
            pp = pp->next->next;
        }
        return false;
    }
};