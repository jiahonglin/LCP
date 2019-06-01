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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> Nodes;
        vector<int> sol;
        if(root != NULL)
            Nodes.push_back(root);
        else
            return sol;
        while(Nodes.empty() == false)
        {
            TreeNode* tmp = Nodes.back();
            Nodes.pop_back();
            sol.push_back(tmp->val);
            if(tmp->right)
                Nodes.push_back(tmp->right);
            if(tmp->left)
                Nodes.push_back(tmp->left);
                
        }
        return sol;
    }
};
