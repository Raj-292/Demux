// https://leetcode.com/problems/binary-tree-right-side-view

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
    void rightSideViewHelper(TreeNode* root, int ht, vector<int>& res) {
        if (!root)
            return;
        
        int n = res.size();
        if (n-1 < ht) {
            res.push_back(root->val);
        }
        
        rightSideViewHelper(root->right, ht+1, res);
        rightSideViewHelper(root->left, ht+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        rightSideViewHelper(root, 0, res);
        
        return res;
    }
};