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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* t = findTreeNode(root,x);
        int leftNodes = countNode(t->left);
        int rightNodes = countNode(t->right);
        if(leftNodes+rightNodes+1<=n/2) return true;
        if(leftNodes > n/2 || rightNodes > n/2) return true;
        return false;
    }
    TreeNode* findTreeNode(TreeNode* root, int x){
        if(!root) return NULL;
        if(root->val == x) return root;
        TreeNode* left = findTreeNode(root->left,x);
        TreeNode* right = findTreeNode(root->right,x);
        return left?left:right;
    }
    int countNode(TreeNode* root){
        if(!root) return 0;
        int left=countNode(root->left);
        int right=countNode(root->right);
        return 1+left+right;
    }
};
