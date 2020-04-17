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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode *pl = l1, *pr = l2, *pcur = &dummy;
        while (pl != NULL && pr != NULL) {
            if (pl->val <= pr->val) {
                pcur->next = pl;
                pl = pl->next;
            } else {
                pcur->next = pr;
                pr = pr->next;
            }
            pcur = pcur->next;
        }       
        while (pl != NULL) {
            pcur->next = pl;
            pl = pl->next;
            pcur = pcur->next;
        }
        while (pr != NULL) {
            pcur->next = pr;
            pr = pr->next;
            pcur = pcur->next;
        }
        return dummy.next;
    }
};