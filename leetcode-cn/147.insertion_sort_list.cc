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
        ListNode *p = head, *qs, *next_p;
        // *qs 链 已经排好序
        // *next_p 下一个需要排序的原链节点
        while (p != NULL)
        {
            next_p = p->next;
            qs = dummy;
            while (qs->next != NULL)
            {
                if (qs->next->val > p->val)
                {
                    break;
                }
                else
                {
                    qs = qs->next;
                }
            }
            p->next = qs->next;
            qs->next = p;
            p = next_p;
        }
        return dummy->next;
    }
};