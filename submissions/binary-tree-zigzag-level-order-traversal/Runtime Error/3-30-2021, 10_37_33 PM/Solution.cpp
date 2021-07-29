// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        vector<stack<TreeNode*>> v(2);
        int level = 0, next_level;
        
        v[level%2].push(root);
        
        while(!v[level%2].empty()) {
            next_level = level+1;
            res.push_back(vector<int>());
            
            while(!v[level%2].empty()) {
                TreeNode* t = v[level%2].top();
                v[level%2].pop();
                
                res[res.size()-1].push_back(t->val);
                
                if(level%2) {
                    if (t->right)
                        v[next_level%2].push(t->right);
                    
                    if (t->left)
                        v[next_level%2].push(t->left);
                    
                } else {
                    if (t->left)
                        v[next_level%2].push(t->left);
                    
                    if (t->right)
                        v[next_level%2].push(t->right);
                }
            }
            
            level = next_level;
        }
        
        return res;
    }
};