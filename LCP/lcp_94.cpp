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
    vector<int> inorderTraversal(TreeNode* root){
        vector<TreeNode*> Nodes;
        TreeNode* cur;
        vector<int> sol;
        cur = root;
        while(Nodes.empty() == false || cur != NULL)
        {
            if(cur)
            {
                Nodes.push_back(cur);
                cur = cur->left;
            }
            else
            {
                cur = Nodes.back();
                sol.push_back(cur->val);
                Nodes.pop_back();
                cur = cur->right;
            }
        }
        return sol;

    }
};
