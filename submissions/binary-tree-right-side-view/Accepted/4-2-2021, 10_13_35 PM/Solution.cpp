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
    void rightSideViewHelper(TreeNode* root, int& ht, vector<int>& res) {
        if (!root)
            return;
        
        if (res.size() <= ht) {
            res.push_back(root->val);
        }
        
        int h = ht+1;
        rightSideViewHelper(root->right, h, res);
        rightSideViewHelper(root->left, h, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int ht = 0;
        rightSideViewHelper(root, ht, res);
        
        return res;
    }
};