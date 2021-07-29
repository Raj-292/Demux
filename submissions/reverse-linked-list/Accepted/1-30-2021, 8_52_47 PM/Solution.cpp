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
    ListNode* reverseList(ListNode* head) {
        ListNode *head_copy = head, *rev_list_head = NULL, *temp;
        
        while(head_copy) {
            temp = head_copy->next;
            
            head_copy->next = rev_list_head;
            rev_list_head = head_copy;
            
            head_copy = temp;
            
        }
        
        return rev_list_head;
    }
};