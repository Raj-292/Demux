// https://leetcode.com/problems/binary-tree-level-order-traversal

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> curr_level;
        vector<TreeNode*> next_level;
        vector<vector<int>> res;
        
        if (!root) return res;
        
        curr_level.push_back(root);
        
        while(!curr_level.empty()) {
            res.push_back(vector<int>());
            for(int i = 0; i < curr_level.size(); i++) {
                res[res.size()-1].push_back(curr_level[i]->val);

                // Push the left child if it exists to the next level
                if (curr_level[i]->left) 
                    next_level.push_back(curr_level[i]->left);

                // Push the right child if it exists to the next level
                if (curr_level[i]->right)
                    next_level.push_back(curr_level[i]->right);
            }
            curr_level = next_level;
            next_level = {};
        }
        
        return res;
        
    }
};