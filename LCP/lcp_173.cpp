/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    TreeNode *cur;
    vector<TreeNode*> Nodes;
    BSTIterator(TreeNode* root) {
        if(root)
        {
            Nodes.push_back(root);
            cur = root;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        cur = Nodes.back();
        if(cur)
        {
            Nodes.push_back(cur->left);
            return next();
        }
        else
        {
            Nodes.pop_back();
            cur = Nodes.back();
            Nodes.pop_back();
            Nodes.push_back(cur->right);
            return cur->val;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        for(int i =0 ; i < Nodes.size();i++)
        {
            if(Nodes[i] != NULL)
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
