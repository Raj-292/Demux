// https://leetcode.com/problems/palindrome-linked-list

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
    bool isPalindrome(ListNode* head) {
        // Find the middle
        ListNode *slow = head, *fast = head, *first_half = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
            
        // Reverse the second half
        ListNode *second_half = NULL, *temp;
        
        while(slow) {
            temp = slow->next;
            slow->next = second_half;
            second_half = slow;
            slow = temp;
        }
            
        // Compare the first half and the second half
        while(first_half && first_half->val == second_half->val) {
            first_half = first_half->next;
            second_half = second_half->next;
        }
        
        if(first_half)
            return false;
        
        return true;
    }
};