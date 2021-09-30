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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int size = q.size();
            while(size){
                TreeNode *t = q.front();q.pop();
                if(t->left == NULL){
                    flag=true;
                }
                else{
                    if(flag) return false;
                    else q.push(t->left);
                }
                if(t->right == NULL){
                    flag=true;
                }
                else{
                    if(flag) return false;
                    else q.push(t->right);
                }
                size--;
            }
        }
        return true;
    }
};
