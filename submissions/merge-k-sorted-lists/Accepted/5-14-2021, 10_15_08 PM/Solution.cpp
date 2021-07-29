// https://leetcode.com/problems/merge-k-sorted-lists

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Push in minq and then pop 
        priority_queue<int,vector<int>,greater<int>> minq;
        for(ListNode* list: lists){
            ListNode* head = list;
            while(head!=NULL){
                minq.push(head->val);
                head=head->next;
            }
        }
        
        // Recreate the sorted list
        ListNode* root = NULL;
        if(minq.size()==0) return root;
        root = new ListNode(minq.top());
        minq.pop();
        ListNode* res = root;
        while(minq.size()){
            ListNode* temp = new ListNode(minq.top());
            root->next = temp;
            root = root->next;
            minq.pop();
        }
        return res;
        
        
        
        // push one element at a time in minq fom all lists -> take the min -> push into the resultant list -> iterate one more element from the list list
        // push the node ,  !value
        // custom comparator -> derive the logic for min heap
        
        
        
    }
};