// https://leetcode.com/problems/binary-tree-level-order-traversal-ii

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<TreeNode*>curr;
        vector<TreeNode*>next;
        
        vector<vector<int>>res;
        
        if(!root) return res;
        
        curr.push_back(root);
        
        while(!curr.empty()){
            next.clear();
            res.push_back(vector<int>());
            for(auto it:curr){
                res[res.size()-1].push_back(it->val);
                if(it->left != NULL){
                    next.push_back(it->left);
                }
                if(it->right !=NULL){
                    next.push_back(it->right);
                }
            }
            curr = next;
            next.clear();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};