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
        // int x;
        // int *y = &x;
        ListNode dummy;
        ListNode *l3_head = &dummy, *l3_tail = &dummy;
        
        ListNode *l1_curr = l1, *l2_curr = l2;
        
        while(l1_curr && l2_curr) {
            // Update l1_curr && insert at the tail
            if(l1_curr->val <= l2_curr->val) {
                l3_tail->next = l1_curr;
                l1_curr = l1_curr->next;
            }
            else {
                l3_tail->next = l2_curr;
                l2_curr = l2_curr->next;
            }
            
            l3_tail = l3_tail->next;
            l3_tail->next = NULL;
        }
        
        // When one of them becomes empty
        if(l1_curr)
            l3_tail->next = l1_curr;
        else
            l3_tail->next = l2_curr;
        
        return l3_head->next;
        
    }
};