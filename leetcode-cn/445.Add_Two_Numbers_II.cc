/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        while (l1 != NULL)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int n1, n2, low_bit = 0;
        ListNode *head = NULL;
        while ((!s1.empty() || !s2.empty()))
        {
            n1 = 0;
            n2 = 0;
            if (!s1.empty())
            {
                n1 = s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                n2 = s2.top();
                s2.pop();
            }
            n1 = n1 + n2 + low_bit;
            auto node = new ListNode(0);
            node->val = n1 % 10;
            low_bit = n1 / 10;
            node->next = head;
            head = node;
        }
        if (low_bit == 1) {
            auto node = new ListNode(1);
            node->next = head;
            head = node;
        }
        return head;
    }
};