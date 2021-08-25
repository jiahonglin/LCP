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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //stack<vector<int>> st;
        vector<vector<int>>sol;
        vector<vector<int>>sol2;
        levelOrder(root,0,sol);
        for(int i=sol.size()-1;i>=0;i--){
            sol2.push_back(sol[i]);
        }
        return sol2;
    }
    void levelOrder(TreeNode* root, int level, vector<vector<int>>& sol){
        if(!root) return;
        if(sol.size() == level) sol.push_back({});
        sol[level].push_back(root->val);
        if(root->left) levelOrder(root->left,level+1,sol);
        if(root->right) levelOrder(root->right,level+1,sol);
    }
};
