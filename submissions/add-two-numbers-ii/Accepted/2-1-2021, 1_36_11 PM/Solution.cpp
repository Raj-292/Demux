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
     ListNode* f(ListNode* li, ListNode* lj, int &carry)
{
    if(!li) {
            carry = 0;
            return NULL;
        }
       
        // Get the sum and carry for the suffix lists
        ListNode *summed_list = f(li->next, lj->next,carry);
    
    int sum = (li->val + lj->val + carry);
    ListNode* temp = new ListNode(sum%10);
    carry = sum/10;
        
    cout<<carry;
    temp->next = summed_list;
    return temp;
}
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1copy =  l1;
        ListNode* l2copy =  l2;
        ListNode* dummy =  new ListNode();
        ListNode* path =   dummy;
        int carry=0;
        
        while(l1copy!=NULL && l2copy!=NULL)
        {
            l1copy = l1copy->next;
            l2copy = l2copy->next;
        }
        
        if(l1copy!=NULL)
        {
            while(l1copy!=NULL)
            {
                ListNode* temp = new ListNode();
                path->next = temp;
                path = path->next;
                path->next = NULL;
                l1copy = l1copy->next;
            }
            path->next = l2;
            dummy = dummy->next;
            
        ListNode *res = f(l1,dummy,carry);
        ListNode *curr = res;
        if(carry) {
            curr = new ListNode(carry);
            curr->next = res;
        }
        
        return curr;
        }
        else if(l2copy!=NULL)
        {
           while(l2copy!=NULL)
            {
                ListNode* temp = new ListNode();
                path->next = temp;
                path = path->next;
                path->next = NULL;
                l2copy = l2copy->next;
            }
            path->next = l1;
            dummy = dummy->next;
            
        ListNode *res = f(dummy,l2,carry);
        ListNode *curr = res;
        if(carry) {
            curr = new ListNode(carry);
            curr->next = res;
        }
        
        return curr; 
        }
        else
        {
        ListNode *res = f(l1,l2,carry);
        ListNode *curr = res;
        if(carry) {
            curr = new ListNode(carry);
            curr->next = res;
        }
        
        return curr;
        }
    }
};
