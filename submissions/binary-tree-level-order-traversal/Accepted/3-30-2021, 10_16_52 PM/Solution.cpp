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
                res[res.size()-1].push_back(q.front()->val);

                // Push the left child if it exists to the next level
                if (q.front()->left) 
                    q.push(q.front()->left);

                // Push the right child if it exists to the next level
                if (q.front()->right)
                    q.push(q.front()->right);
                
                q.pop();
            }
        }
        
        return res;
        
    }
};