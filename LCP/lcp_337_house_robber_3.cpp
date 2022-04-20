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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int> m;
        return dfs(root,m);
    }
    int dfs(TreeNode* root, unordered_map<TreeNode*,int>& m){
        if(!root) return 0;
        if(m.count(root)) return m[root];
        int val = 0;
        if(root->left){
            val+=dfs(root->left->left,m)+dfs(root->left->right,m);
        }
        if(root->right){
            val+=dfs(root->right->left,m)+dfs(root->right->right,m);
        }
        m[root] = max(root->val+val, dfs(root->left,m)+dfs(root->right,m));
        return m[root];
    }
};
