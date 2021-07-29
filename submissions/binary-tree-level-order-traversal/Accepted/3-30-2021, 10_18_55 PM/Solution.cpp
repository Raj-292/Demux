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
        queue<TreeNode *> q;
        vector<vector<int>> res;
        
        if (!root) return res;
        
        q.push(root);
        
        while(!q.empty()) {
            res.push_back(vector<int>());
            int n = q.size();
            for(int i = 0; i < n; i++) {
                TreeNode *t = q.front();
                q.pop();
                
                res[res.size()-1].push_back(t->val);

                // Push the left child if it exists to the next level
                if (t->left) 
                    q.push(t->left);

                // Push the right child if it exists to the next level
                if (t->right)
                    q.push(t->right);
            }
        }
        
        return res;
        
    }
};