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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy;
        ListNode *pa = head, *pb, *pc;
        dummy.next = head;
        head = &dummy;
        while (pa != NULL && pa->next != NULL) {
            pb = pa->next;
            pc = pb->next;
            head->next = pb;
            pb->next = pa;
            pa->next = pc;
            head = pa;
            pa = pc;
        }
        return dummy.next;
    }
};