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

    string strPreOrder;

    void Preorder(TreeNode* root)
    {
        if(root)
        {
            strPreOrder += std::to_string(root->val);
            strPreOrder += " ";
            Preorder(root->left);
            Preorder(root->right);
        }
        else
        {
            strPreOrder += "n ";
        }
    }

    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "n") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        Preorder(root);
        return strPreOrder;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    
};

// Your Codecc object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
