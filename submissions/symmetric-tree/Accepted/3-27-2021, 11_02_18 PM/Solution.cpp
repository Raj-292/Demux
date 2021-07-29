// https://leetcode.com/problems/symmetric-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // jg = jai gurudev
    // jai shree ram
    bool areSymmetric(TreeNode* t1, TreeNode* t2) {
        // Base cases
        if (!t1 && !t2) return true;
        
        if (!t1 || !t2) return false;
        
        // Recursive case
        return t1->val == t2->val && 
               areSymmetric(t1->left, t2->right) &&
               areSymmetric(t1->right, t2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return areSymmetric(root->left, root->right);   
    }
};