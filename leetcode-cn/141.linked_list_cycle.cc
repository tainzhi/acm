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
		ListNode * p = head, *pp = head;
		while (p != nullptr && pp != nullptr && pp->next != nullptr ) {
			p = p->next;
			pp = pp->next->next;
			if (p == pp) return true;
		}
		return false;
    }
};