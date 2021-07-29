// https://leetcode.com/problems/serialize-and-deserialize-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder_serialize(TreeNode* root, string& serial) {
        if (!root) {
            serial += ",null";
            return;
        }
        
        serial = serial + "," + to_string(root->val);
        
        preorder_serialize(root->left, serial);
        preorder_serialize(root->right, serial);
    }
    
    TreeNode* preorder_deserialize(stringstream& ss) {
        string val;
        getline(ss, val, ',');
        
        if (val == "null") {
            return NULL;
        }
    
        TreeNode *node = new TreeNode(stoi(val));
        
        node->left = preorder_deserialize(ss);
        node->right = preorder_deserialize(ss);
        
        return node;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial = "";
        
        preorder_serialize(root, serial);
        return serial.substr(1, (int)serial.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        
        return preorder_deserialize(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));