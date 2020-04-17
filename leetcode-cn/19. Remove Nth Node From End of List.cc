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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pa = head, *pb = NULL;
        int count = 0;
        while (count < n) {
            pa = pa->next;
            count++;
        }
        pb = pa;
        pa = head;
        while (pb != NULL) {
            if (pb->next == NULL) {
                pa->next = pa->next->next;
                break;
            }
            pb = pb->next;
            pa = pa->next;
        }
        if (pb == NULL && pa == head) {
            head = head->next;
        }
        return head;
    }
};