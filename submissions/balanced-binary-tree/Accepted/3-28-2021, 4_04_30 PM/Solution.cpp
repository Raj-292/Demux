// https://leetcode.com/problems/balanced-binary-tree

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
    // Returns true if the subtree is balanced. It also returns the height of the tree.
    bool isBalancedHelper(TreeNode* root, int &height) {
        // Base case
        if (!root) {
            // height = 0;
            return true;
        }
        
        // Recursive step
        bool ans_l, ans_r;
        int height_l = 0, height_r = 0;
        
        // Get the height and the answer for the left subtree
        ans_l = isBalancedHelper(root->left, height_l);
        
        // Get the height and the answer for the right subtree
        ans_r = isBalancedHelper(root->right, height_r);
        
        // Compute
        height = 1 + max(height_l, height_r);
        
        return ans_l && ans_r && abs(height_l-height_r) <= 1;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        
        return isBalancedHelper(root, height);
    }
};