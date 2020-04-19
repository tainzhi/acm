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
    ListNode *insertionSortList(ListNode *head)
    {
        auto dummy = new ListNode(0);
        ListNode *p = head, *q;
        while (p != NULL)
        {
            head = p->next;
            q = dummy;
            while (q->next != NULL)
            {
                if (q->next->val > p->val)
                {
                    break;
                }
                else
                {
                    q = q->next;
                }
            }
            p->next = q->next;
            q->next = p;
            p = head;
        }
        return dummy->next;
    }
};