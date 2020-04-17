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
    ListNode* reverseList(ListNode* head) {
        ListNode * pa = head, *pb = NULL, *pc;
        while (pa != NULL) {
            pc = pa;
            pa = pa->next;
            pc->next = pb;
            pb = pc;
        }
        return pb;
    }
};