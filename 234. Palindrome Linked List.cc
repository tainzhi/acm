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
    ListNode* frontHead;
    bool recursivelyCheck(ListNode* head) {
        if (head != NULL) {
            if (!recursivelyCheck(head->next)) return false;
            if (frontHead->val != head->val) return false;
            frontHead = frontHead->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        frontHead = head;
        return recursivelyCheck(head);
    }
};