// https://leetcode.com/problems/path-sum

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
    void hasPathSumHelper(TreeNode* root, int& contri, int targetSum, bool& res) {
        if (!root)
            return;
        
        // Validation at the leaf node
        if (!root->left && !root->right){
            res = res || contri+root->val == targetSum;
            return;
        }
        
        // Recursive Step
        int d = contri+root->val;
        hasPathSumHelper(root->left, d, targetSum, res);
        hasPathSumHelper(root->right, d, targetSum, res);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = false;
        
        int contri = 0;
        hasPathSumHelper(root, contri, targetSum, res);
        
        return res;
    }
};