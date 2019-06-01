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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> NodesA;
        vector<int> sol;
        if(root)
            NodesA.push_back(root);
        else
            return sol;

        while(NodesA.empty() == false)
        {
            TreeNode* tmp = NodesA.back();
            sol.insert(sol.begin(), tmp->val);
            NodesA.pop_back();
            if(tmp->left)
                NodesA.push_back(tmp->left);
            if(tmp->right)
                NodesA.push_back(tmp->right);
        }
        return sol;
    }
};
