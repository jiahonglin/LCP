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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
    void isValidBST(TreeNode* nd, vector<int> &inorderVec)
    {
        if(!nd) return;
        isValidBST(nd->left, inorderVec);
        inorderVec.push_back(nd->val);
        isValidBST(nd->right, inorderVec);
    }
    bool isValidBST(TreeNode* nd, long max, long min)
    {
        if(!nd) return true;
        if(nd->val >= max || nd->val <= min) return false;
        return isValidBST(nd->left, nd->val, min) && isValidBST(nd->right, max, nd->val);
    }
};
