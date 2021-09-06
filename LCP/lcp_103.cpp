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
    /*PreOrder*/
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        preOrderTraverse(root,0,sol);
        return sol;
    }
    void preOrderTraverse(TreeNode* root, int level, vector<vector<int>>& sol){
        if(!root) return;
        if(sol.size()<=level){
            sol.push_back({});
        }
        vector<int> &oneLevel = sol[level];
        if(level%2 == 0) oneLevel.push_back(root->val);
        else oneLevel.insert(oneLevel.begin(),root->val);
        preOrderTraverse(root->left,level+1,sol);
        preOrderTraverse(root->right,level+1,sol);
    }
    /*Ierative*/
    /*
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return{};
        queue<TreeNode*> q;
        q.push(root);
        bool rev=true;
        vector<vector<int>> sol;
        while(!q.empty()){
            vector<int> level;
            rev^=1;
            for(int i=q.size();i>0;i--){
                TreeNode* t = q.front();q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                level.push_back(t->val);
            }
            if(!rev) sol.push_back(level);
            else {
                reverse(level.begin(),level.end());
                sol.push_back(level);
            }
        }
        return sol;
    }
    */
};
