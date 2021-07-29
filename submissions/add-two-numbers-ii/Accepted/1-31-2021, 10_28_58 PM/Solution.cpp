// https://leetcode.com/problems/add-two-numbers-ii

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
    ListNode* f(ListNode* l1, ListNode* l2, int &carry) {
        if(!l1) {
            carry = 0;
            return NULL;
        }
        
        // Get the sum and carry for the suffix lists
        int passed_carry;
        ListNode *summed_list = f(l1->next, l2->next, passed_carry);
        
        // Combining step
        int curr_elt = (l1->val + l2->val + passed_carry)%10;
        int curr_carry = (l1->val + l2->val + passed_carry)/10;
        
        ListNode *curr_node = new ListNode(curr_elt);
        
        curr_node->next = summed_list;
        // Implicit return
        carry = curr_carry;
        
        // Explicit return
        return curr_node;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Padding logic
        ListNode *curr_l1 = l1, *curr_l2 = l2;
        
        while(curr_l1 && curr_l2) {
            curr_l1 = curr_l1->next;
            curr_l2 = curr_l2->next;
        }
        
        ListNode dummy;
        ListNode *new_l1, *new_l2, *pad_list = &dummy, *rem_list;
        
        if(curr_l1) {
            rem_list = curr_l1;
            new_l1 = l1;
            pad_list->next = l2;
        }
        else {
            rem_list = curr_l2;
            new_l1 = l2;
            pad_list->next = l1;
        }
        
        while(rem_list) {
            ListNode *temp = new ListNode(0);
            temp->next = pad_list->next;
            pad_list->next = temp;

            rem_list = rem_list->next;
        }
        
        // pad_list contains all 0s
        // new_l1 points to the bigger list
        // initialize new_l2
        new_l2 = pad_list->next;
        
        
        int carry;
        ListNode *res = f(new_l1,new_l2,carry);
        ListNode *curr = res;
        if(carry) {
            curr = new ListNode(carry);
            curr->next = res;
        }
        
        return curr;
    }
};