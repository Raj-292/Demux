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
    bool lca(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode** res){
        if(root ==  NULL){
            return false;
        }
        
        bool f1 = lca(root->left,p,q,res);
        bool f2 = lca(root->right,p,q,res);
        
        if((f1 && f2) || (root == p || root == q) && (f1 || f2)){
            *res = root;
        }
        
        return (f1 || f2 || root == p || root == q);
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res ==  NULL;
        
        bool r = lca(root,p,q,&res);
        
        return res;
    }
};