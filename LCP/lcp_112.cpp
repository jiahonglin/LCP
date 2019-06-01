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
    bool hasPath = false;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root){
            traceTreeSum(root, 0, sum);
        }
        return hasPath;     
    }

    void traceTreeSum(TreeNode* node, int curSum, int goalSum){
        curSum += node->val;
        if(node->left == NULL && node->right == NULL && curSum == goalSum)
            hasPath = true;
        if(node->left)
            traceTreeSum(node->left, curSum, goalSum);
        if(node->right)
            traceTreeSum(node->right, curSum, goalSum);
    }
};
