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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* tmp = root;
        if(!root->left && !root->right && root->val==0){
            return NULL;
        }
        tmp->left = pruneTree(root->left);
        tmp->right = pruneTree(root->right);
        if(!tmp->left && !tmp->right && tmp->val == 0) tmp=NULL;
        return tmp;
    }
};
