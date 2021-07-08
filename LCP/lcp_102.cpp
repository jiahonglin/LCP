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
    
    /*Recursive*/
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        levelOrder(root,0,sol);
        return sol;
    }
    void levelOrder(TreeNode* node, int level, vector<vector<int>>& sol){
        if(!node) return;
        if(sol.size() == level) sol.push_back({});
        sol[level].push_back(node->val);
        if(node->left) levelOrder(node->left,level+1,sol);
        if(node->right) levelOrder(node->right,level+1,sol);
    }
    /*Iterative*/
    /*
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        queue<TreeNode*> q{{root}};
        vector<vector<int>> sol;
        while(!q.empty()){
            vector<int> levelElem;
            for(int i=q.size();i>0;i--){
                TreeNode* t = q.front(); q.pop();
                levelElem.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            sol.push_back(levelElem);
        }
        return sol;
    }
    */
};
