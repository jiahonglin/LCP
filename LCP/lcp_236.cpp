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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;

        if(root->val == p->val || root->val == q->val)
            return root;

        TreeNode* left_lca = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_lca = lowestCommonAncestor(root->right,p,q);

        if(left_lca && right_lca)
            return root;
        return left_lca?left_lca:right_lca;
    }
};
