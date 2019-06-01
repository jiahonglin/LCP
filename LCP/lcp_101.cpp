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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return determineIsSym(root->left, root->right);
    }
    bool determineIsSym(TreeNode* left, TreeNode* right)
    {
        if((left == NULL) && (right == NULL))
            return true;
        if((left == NULL) && (right != NULL))
            return false;
        if((left != NULL) && (right == NULL))
            return false;
        if(left->val != right->val)
            return false;
        if(!determineIsSym(left->left, right->right))
            return false;
        if(!determineIsSym(left->right, right->left))
            return false;
        return true;
    }
};
