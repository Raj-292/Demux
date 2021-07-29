// https://leetcode.com/problems/validate-binary-search-tree

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
    // It returns whether the tree rooted at "root" is a valid bst.
    // It also returns the largest and the smallest nodes of the tree
    // rooted at "root".
    bool isValidBSTHelper(TreeNode* root, int& min_elt, int& max_elt) {
        // Base case
        if (!root) {
            min_elt = INT_MAX;
            max_elt = INT_MIN;
            return true;
        }
        
        // Recursive step.
        bool ans_l, ans_r;
        int min_left, max_left, min_right, max_right;
        
        // Get for the left subtree
        ans_l = isValidBSTHelper(root->left, min_left, max_left);
        
        // Get for the right subtree
        ans_r = isValidBSTHelper(root->right, min_right, max_right);
        
        // combine
        min_elt = min(root->val, min(min_left, min_right));
        max_elt = max(root->val, max(max_left, max_right));
        
        return ans_l && ans_r && (root->val > max_left && root->val < min_right);
    }
    bool isValidBST(TreeNode* root) {
        int min_elt = INT_MAX, max_elt = INT_MIN;
        
        return isValidBSTHelper(root, min_elt, max_elt);
    }
};