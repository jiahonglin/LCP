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
    TreeNode *OrgRoot;
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        OrgRoot = root;
        TreeNode *NodePos = findInsertPos(root,val);
        if(NodePos->val > val)
            NodePos->left = new TreeNode(val);
        else
            NodePos->right = new TreeNode(val);
        return OrgRoot;
    }
    TreeNode* findInsertPos(TreeNode* n, int val){
        if(val < n->val)
        {
            if(n->left)
            {
                return findInsertPos(n->left,val);
            }
        }
        else
        {
            if(n->right)
            {
                return findInsertPos(n->right, val);
            }
        }
        return n;
    }
};
