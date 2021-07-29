// https://leetcode.com/problems/remove-linked-list-elements

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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *p1, *prevp1;
        
        p1 = prevp1 = head;
        
        while(p1){
            if(p1->val == val){
                prevp1->next = p1->next;
            }
            prevp1 = p1;
            p1 = p1->next;
        }
        return head;
    }
};