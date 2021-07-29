// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** res) {
        if (!root)
            return false;
        
        bool l1 = lowestCommonAncestorHelper(root->left, p, q, res);
        bool l2 = lowestCommonAncestorHelper(root->right, p, q, res);
        
        if (!(*res)) {
            if ((l1 && l2) || ((root == p || root == q) && (l1 || l2)))
                (*res) = root;
        }
        
        return (l1 || l2 || root == p || root == q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = NULL;
        
        bool l = lowestCommonAncestorHelper(root, p, q, &res);
        
        return res;
    }
};