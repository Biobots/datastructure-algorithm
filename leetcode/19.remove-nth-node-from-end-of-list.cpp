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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        ListNode* rst;
        ListNode* pre;
        ListNode* ptr = head;
        for(int i=0; i<n-1; i++)
        {
            ptr=ptr->next;
        }
        rst=head;
        while(ptr->next)
        {
            pre=rst;
            ptr=ptr->next;
            rst=rst->next;
        }
        if(rst==head) return rst->next;
        pre->next=rst->next;
        return head;
    }
};