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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head, *p2, *prevP2;

        while (n) {
            p1 = p1->next;
            n--;
        }

        p2 = head;
        prevP2 = NULL;
        while (p1) {
            prevP2 = p2;
            p2 = p2->next;
            p1 = p1->next;
        }

        // Trying to delete the head
        if (!prevP2) {
            return p2->next;
        }
        else {
            prevP2->next = p2->next;
            return head;
        }

        // NF - Doesn't reach here
        return head;
    }
};