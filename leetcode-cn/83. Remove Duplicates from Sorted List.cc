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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * pLast = head, *pCur = head;
        while (pCur != NULL) {
            if (pLast != pCur && pLast->val != pCur->val) {
                pLast->next = pCur;
                pLast = pCur;
            }
            pCur = pCur->next;
        }       
        if (pLast->next != NULL) {
            pLast->next = NULL;
        }
        return head;
    }
};