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
    int ans = 0;
    int maxDepth(TreeNode* root) {
        maxDepthSearch(root, 1);
        return ans;
    }
    void maxDepthSearch(TreeNode* r, int depth)
    {
        if(!r)
            return;
        ans = (ans<depth)?depth:ans;
        maxDepthSearch(r->left, depth+1);
        maxDepthSearch(r->right, depth+1);
    }
};
