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
    /*
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MAX, LONG_MIN);
    }
    bool isValidBST(TreeNode* nd, long max, long min)
    {
        if(!nd) return true;
        if(nd->val >= max || nd->val <= min) return false;
        return isValidBST(nd->left, nd->val, min) && isValidBST(nd->right, max, nd->val);
    }
*/
    /*Method2 inorder traversal*/
    
    bool isValidBST(TreeNode* root) {
        vector<int> inorderVec;
        if(!root) return true;
        isValidBST(root, inorderVec);
        for(int i = 0; i < inorderVec.size()-1 ; i++)
        {
            if (inorderVec[i] >= inorderVec[i+1])
            {
                return false;
            }
        }
        return true;

    }
    void isValidBST(TreeNode* nd, vector<int> &inorderVec)
    {
        if(!nd) return;
        isValidBST(nd->left, inorderVec);
        inorderVec.push_back(nd->val);
        isValidBST(nd->right, inorderVec);
    }
    /*Method 3*/ 
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }
    bool isValidBST(TreeNode* node, long int low, long int high){
        if(!node) return true;
        if(node->val <= low || node->val >= high) return false;
        return isValidBST(node->left, low, node->val) && isValidBST(node->right, node->val, high);
    }
    
};
