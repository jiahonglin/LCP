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
    /*Method 2*/
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> out;
        vector<vector<int>> sol;
        traverse(root,targetSum,out,sol);
        return sol;
    }
    void traverse(TreeNode* cur, int targetSum, vector<int>& out, vector<vector<int>>& sol){
        if(!cur) return;
        out.push_back(cur->val);
        targetSum-=cur->val;
        if(!cur->left && !cur->right && targetSum==0){ sol.push_back(out); }
        traverse(cur->left, targetSum, out, sol);
        traverse(cur->right, targetSum, out, sol);
        out.pop_back();
    }
    /*Method 1*/
    /*
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> out;
        vector<vector<int>> sol;
        traverse(root,targetSum,out,sol);
        return sol;
    }
    void traverse(TreeNode* cur, int targetSum, vector<int>& out, vector<vector<int>>& sol){
        if(!cur->left && !cur->right){
            out.push_back(cur->val);
            if(accumulate(out.begin(),out.end(),0) == targetSum){
                sol.push_back(out);
            }
            out.pop_back();
            return;
        }
        out.push_back(cur->val);
        if(cur->left){
            traverse(cur->left,targetSum,out,sol);
        }
        if(cur->right){
            traverse(cur->right,targetSum,out,sol);
        }
        out.pop_back();
    }
    */
};
