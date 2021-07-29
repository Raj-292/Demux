// https://leetcode.com/problems/merge-two-sorted-lists

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
        ListNode* l1copy = l1;
        ListNode* l2copy = l2;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int max=0;
        while(l1copy!= NULL || l2copy!=NULL)
        {
            if(l1copy!= NULL && l2copy!=NULL)
            {
                if(l1copy->val <= l2copy->val)
                {
                    max = l1copy->val;
                    l1copy = l1copy->next;
                }
                else
                {
                  max = l2copy->val;
                  l2copy = l2copy->next;  
                }
                
                ListNode* temp = new ListNode(max);
                curr->next = temp;
                curr = curr->next;
            }
            
            else if(l1copy!= NULL)
            {
                max = l1copy->val;
                l1copy = l1copy->next;
                ListNode* temp = new ListNode(max);
                curr->next = temp;
                curr = curr->next;
            }
            else
            {
                max = l2copy->val;
                l2copy = l2copy->next;
                ListNode* temp = new ListNode(max);
                curr->next = temp;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};