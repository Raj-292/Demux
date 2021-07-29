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
    
    TreeNode* preorder_deserialize(vector<string>& serial, int& idx) {
        if (serial[idx] == "null") {
            idx++;
            return NULL;
        }
    
        TreeNode *node = new TreeNode(stoi(serial[idx]));
        idx++;
        
        node->left = preorder_deserialize(serial, idx);
        node->right = preorder_deserialize(serial, idx);
        
        return node;
    }
    vector<string> split (const string &s, char delim) {
        vector<string> result;
        stringstream ss (s);
        string item;

        while (getline (ss, item, delim)) {
            result.push_back (item);
        }

        return result;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serial = "";
        
        preorder_serialize(root, serial);
        return serial.substr(1, (int)serial.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> serial = split(data, ',');
        int idx = 0;
        
        TreeNode* root = preorder_deserialize(serial, idx);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));