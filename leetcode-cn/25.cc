/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * dummy = new ListNode(0, head), * pre, * p;
        pre = dummy;
        while (pre ->next != nullptr) {
            p = pre;
            for (int i = 0; i < k && p != nullptr; i++) {
                p = p->next;
            }
            pair<ListNode *, ListNode *> newHeadTail = reverse(pre->next, p);
            pre->next = newHeadTail.first;
            pre= newHeadTail.second;
        }
        return dummy->next;
    }

    pair<ListNode*,ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode * dummy = new ListNode(0, tail->next), *reTail = head;
        ListNode * p = head, *tmp, *np = dummy;
        while (p != tail) {
            tmp = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = tmp;
        }
        return pair(dummy->next, reTail);
    }
};
// @lc code=end

