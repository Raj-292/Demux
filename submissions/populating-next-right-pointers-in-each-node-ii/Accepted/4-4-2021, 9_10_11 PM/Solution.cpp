// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii

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
        Node* curr_node = root;
        Node* prev_node = NULL;
        Node* first_node_next_level = NULL;
        
        while(curr_level) {
            while(curr_node) {
                if (curr_node->left) {
                    if (prev_node)
                        prev_node->next = curr_node->left;
                    prev_node = curr_node->left;
                    
                    if (!first_node_next_level)
                        first_node_next_level = curr_node->left;
                }
                if (curr_node->right) {
                    if (prev_node)
                        prev_node->next = curr_node->right;
                    prev_node = curr_node->right;
                    
                    if (!first_node_next_level)
                        first_node_next_level = curr_node->right;
                }
                
                curr_node = curr_node->next;
            }
            
            curr_level = curr_node = first_node_next_level;
            first_node_next_level = NULL;
            prev_node = NULL;
        }
        
        return root;
    }
};