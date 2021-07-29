// https://leetcode.com/problems/reverse-linked-list

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
    void f(ListNode* head, ListNode** new_head, ListNode** new_tail) {
        if(!head) return;
        
        f(head->next, new_head, new_tail);
        
        (*new_tail)->next = head;
        (*new_tail) = (*new_tail)->next;

        
        head->next = NULL;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *new_head, *new_tail;
        ListNode dummy;
        
        new_head = new_tail = &dummy;
        
        f(head, &new_head, &new_tail);
        
        return new_head->next;
    }
};