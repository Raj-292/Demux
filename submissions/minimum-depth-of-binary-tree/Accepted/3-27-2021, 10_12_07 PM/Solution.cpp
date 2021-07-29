// https://leetcode.com/problems/minimum-depth-of-binary-tree

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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        int left_ans = INT_MAX, right_ans = INT_MAX;
        
        if(root->left)
            left_ans = minDepth(root->left);
        
        if(root->right)
            right_ans = minDepth(root->right);
        
        if(left_ans == INT_MAX && right_ans == INT_MAX)
            return 1;
        
        return 1+min(left_ans, right_ans);
    }
};