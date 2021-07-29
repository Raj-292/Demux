// https://leetcode.com/problems/reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *r,*q,*p,*res;
        p=head;
        r=head;
        int num=0;
        while(r)
        {
            num++;
            r=r->next;
        }
        int flag=0;
        int val=num/k;
        ListNode *point2=NULL;
        while(val--)
        {
            r=NULL;
            q=NULL;
            int count=0;ListNode *point=p;
            while(count!=k)
            {
                r=q;
                q=p;
                p=p->next;
                q->next=r;
                count++;  
            }
            if(flag==0)res=q,flag++;
            point->next=p;
            if(point2)point2->next=q;
            point2=point;
        }
        return res;
    }
};