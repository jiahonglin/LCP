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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodelist;
        inorderTraverse(root,nodelist);
        return nodelist[k-1];
    }
    void inorderTraverse(TreeNode* root, vector<int>& nodelist){
        if(!root) return;
        inorderTraverse(root->left,nodelist);
        nodelist.push_back(root->val);
        inorderTraverse(root->right,nodelist);
    }
};
