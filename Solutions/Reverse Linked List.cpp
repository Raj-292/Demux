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

        while (head_copy) {
            temp = head_copy->next;

            head_copy->next = rev_list_head;
            rev_list_head = head_copy;

            head_copy = temp;

        }

        return rev_list_head;
    }
};

//Recursive :

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
        if (!head) return;

        f(head->next);

        if (!new_tail)
            new_tail = new_head = head;
        else {
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

// Stop recursion before reaching NULL

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
        if (!head->next) {
            new_tail = new_head = head;
            //head->next = NULL; Not needed
            return;
        }

        f(head->next);

        new_tail->next = head;
        new_tail = new_tail->next;


        head->next = NULL;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;

        f(head);

        return new_head;
    }
};

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
        if (!head->next) {
            new_tail = new_head = head;
            return;
        }

        f(head->next);

        new_tail->next = head;
        new_tail = new_tail->next;


        head->next = NULL;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;

        f(head);

        return new_head;
    }
};

// Removing if/else

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
    ListNode dummy;

    Solution() {
        // Dummy node
        new_head = new_tail = &dummy;
    }

    void f(ListNode* head) {
        if (!head) return;

        f(head->next);

        new_tail->next = head;
        new_tail = new_tail->next;


        head->next = NULL;
    }

    ListNode* reverseList(ListNode* head) {
        f(head);

        return new_head->next;
    }
};

// pass by reference

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
        if (!head) return;

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