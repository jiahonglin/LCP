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
//method 1
/*
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(nodeDeath(root->left) - nodeDeath(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
    int nodeDeath(TreeNode* root)
    {
        if(!root) return 0;
        return 1 + max(nodeDeath(root->left), nodeDeath(root->right));
    }
*/
//method 2
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(checkDeath(root) == -1) return false;
        return true;
    }
    
    int checkDeath(TreeNode* root)
    {
        if(!root) return 0;
        int left = checkDeath(root->left);
        if(left == -1) return -1;
        int right = checkDeath(root->right);
        if(right == -1) return -1;
        int diff = abs(left-right);
        if(diff > 1) return -1;
        else return 1+max(left,right);
    }
};
