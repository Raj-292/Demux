// https://leetcode.com/problems/populating-next-right-pointers-in-each-node

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        root->next = NULL;
        Node* curr_level = root;
        Node *curr_node = curr_level;
        
        while(curr_level) {
            while(curr_node) {
                if (curr_node->left) {
                    curr_node->left->next = curr_node->right;
                    if (curr_node->next)
                        curr_node->right->next = curr_node->next->left;
                    else
                        curr_node->right->next = NULL;
                }
                curr_node = curr_node->next;
            }
            
            curr_node = curr_level->left;
            curr_level = curr_node;
        }
        
        return root;
        
    }
};