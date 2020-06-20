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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* rst;
        ListNode* head;
        if(l1->val<=l2->val)
        {
            rst = p1;
            head = rst;
            if(!p1->next)
            {
                rst->next = p2;
                return head;
            }
            p1 = p1->next;
        }
        else
        {
            rst = p2;
            head = rst;
            if(!p2->next)
            {
                rst->next = p1;
                return head;
            }
            p2 = p2->next;
        }
        while(p1 && p2)
        {
            if(p1->val<=p2->val)
            {
                rst->next = p1;
                p1 = p1->next;
            }
            else
            {
                rst->next = p2;
                p2 = p2->next;
            }
            rst = rst->next;
        }
        if(p1)
        {
            rst->next = p1;
        }
        else if(p2)
        {
            rst->next = p2;
        }
        return head;
    }
};