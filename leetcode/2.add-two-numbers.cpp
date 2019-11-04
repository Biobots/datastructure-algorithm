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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a = l1->val + l2->val;
        int tmp;
        tmp = a / 10;
        a = a % 10;
        ListNode* first = new ListNode(a);
        ListNode* ptr = first;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int x, y;
        while (t1->next != NULL || t2->next != NULL)
        {
            x = t1->next != NULL ? t1->next->val : 0;
            y = t2->next != NULL ? t2->next->val : 0;
            a = x + y + tmp;
            tmp = a / 10;
            a %= 10;
            ListNode* node = new ListNode(a);
            ptr->next = node;
            ptr = node;
            if (t1->next != NULL) t1 = t1->next;
            if (t2->next != NULL) t2 = t2->next;
        }
        if (tmp != 0)
        {
            ListNode* node = new ListNode(tmp);
            ptr->next = node;
        }
        return first;
    }
};