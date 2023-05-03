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
    /*
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> sol;
        q.push(root);
        while(!q.empty()){
            vector<int> levelNode;
            for(int i=q.size();i>0;i--){
                TreeNode* t=q.front(); q.pop();
                levelNode.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            sol.push_back(levelNode.back());
        }
        return sol;
    }
    */
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            TreeNode* t;
            for(int i=0;i<sz;i++){
                t = q.front();q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(t->val);
        }
        return ans;
    }
};
