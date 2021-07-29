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
    vector<vector<int>> levelOrderBottomHelper(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return {};
        }
        
        int hl, hr;
        vector<vector<int>> rl, rr;
        rl = levelOrderBottomHelper(root->left, hl);
        rr = levelOrderBottomHelper(root->right, hr);
        
        int curr_ht = 1 + max(hl, hr);
        
        cout << hl << ", " << hr << endl;
        cout << rl.size() << ", " << rr.size() << endl;

        vector<vector<int>> r;
        bool is_left_smaller = false;
        
        if (hr > hl)
            is_left_smaller = true;
        else
            is_left_smaller = false;
        
        int smaller_len = min(hl, hr);
        int larger_len = max(hl, hr);
        
        for (int i = 0; i < smaller_len; i++) {
            if (is_left_smaller)
                r.push_back(rr[i]);
            else
                r.push_back(rl[i]);
        }
        
        int upper_boun;
        
        if (smaller_len == larger_len)
            upper_boun = larger_len;
        else
            upper_boun = larger_len-1;
        
        for (int i = min(hl, hr); i <= upper_boun; i++) {
            if (is_left_smaller) {
                r.push_back(rl[i-min(hl, hr)]);
                r[(int)r.size()-1].insert(r[(int)r.size()-1].end(), rr[i].begin(), rr[i].end());
            }
            else {
                r.push_back(rl[i]);
                r[(int)r.size()-1].insert(r[(int)r.size()-1].end(), rr[i-min(hl, hr)].begin(), rr[i-min(hl, hr)].end());
            }
        }
        
        // Push this current element
        if ((int)r.size() < curr_ht)
            r.push_back({});
        
        r[curr_ht-1].push_back(root->val);
        
        height = curr_ht;
        return r;
    }
//     int getHeight(TreeNode* root) {
//         if (!root)
//             return 0;
        
//         return 1 + max(getHeight(root->left), getHeight(root->right));
//     }
    
//     void levelOrderBottomHelper(TreeNode* root, int height, vector<vector<int>>& res) {
//         if (!root)
//             return;
        
//         res[height-1].push_back(root->val);
        
//         levelOrderBottomHelper(root->left, height-1, res);
//         levelOrderBottomHelper(root->right, height-1, res);
    // }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int ht;
        return levelOrderBottomHelper(root, ht);
    }
};