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
    TreeNode* searchBST(TreeNode* root, int val) {
        //TreeNode *sol;
        if(root->val == val) return root;
        if(root->val > val)
        {
            if(root->left) 
            {
                return searchBST(root->left, val);
            }
            else
            {
                return root->left;
            }
        }
        else
        {
            if(root->right)
            {
                return searchBST(root->right, val);
            }
            else
            {
                return root->right;
            }
        }
    }
};
