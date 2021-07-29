// https://leetcode.com/problems/maximum-depth-of-binary-tree

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
  void maxDepthhelper(TreeNode* root,int &contri,int &res)
    {
       if(root==NULL) return ;
        if(!root->left && !root->right)
        {
             res=max(res,1+contri);
             return;
        }
      
        maxDepthhelper(root->left,contri+1,&res);
        maxDepthhelper(root->right,contri+1,&res);
        
    }
    int maxDepth(TreeNode* root) {
        int contri=0;
        int res=0;
        maxDepthhelper(root,contri,res);
        return res;
        
    }
};