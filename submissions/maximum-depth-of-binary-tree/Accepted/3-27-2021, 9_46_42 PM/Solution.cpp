// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
    void maxDepthHelper(TreeNode* root, int contri, int& res) {
        // Base case
        if (!root) return;
        
        // Update the contri only at a leaf
        if (!root->left && !root->right) {
            res = max(res, 1+contri);
            return;
        }
        
        // Recursive step
        maxDepthHelper(root->left, contri+1, res);
        maxDepthHelper(root->right, contri+1, res);
    }
    int maxDepth(TreeNode* root) {
        int res = 0;
        
        maxDepthHelper(root, 0, res);
        
        return res;
    }
};