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
        if (head == NULL) {
            return false;
        }
        ListNode * p1 = head, *p2 = head->next;
        while (p1 !=  NULL && p2 != NULL && p2->next != NULL) {
            if (p1 == p2) {
                return true;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return false;
    }
};