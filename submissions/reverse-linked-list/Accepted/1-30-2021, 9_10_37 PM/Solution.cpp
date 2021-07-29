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
    ListNode *new_head, *new_tail;
    
    Solution() {
        new_head = new_tail = NULL;
    }
    
    void f(ListNode* head) {
        if(!head) return;
        
        f(head->next);
        
        if(!new_tail)
            new_tail = new_head = head;
        else{
            new_tail->next = head;
            new_tail = new_tail->next;
        }
        
        head->next = NULL;
    }
    
    ListNode* reverseList(ListNode* head) {
        f(head);
        
        return new_head;
    }
};