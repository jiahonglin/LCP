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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Val;
        vector<int> root2Val;
        vector<int> res;
        inorder(root1, root1Val);
        inorder(root2, root2Val);
        int i=0;
        int j=0;
        while(i < root1Val.size()&& j < root2Val.size()){
            if(root1Val[i]<root2Val[j])
                res.push_back(root1Val[i++]);
            else
                res.push_back(root2Val[j++]);
        }
        if(i>=root1Val.size()){
            for(int m=j;m<root2Val.size();m++) res.push_back(root2Val[m]);
        }
        else{
            for(int m=i;m<root1Val.size();m++) res.push_back(root1Val[m]);
        }
        return res;
    }
    void inorder(TreeNode* root, vector<int>& sol){
        if(!root) return;
        if(root->left) inorder(root->left,sol);
        sol.push_back(root->val);
        if(root->right) inorder(root->right,sol);
    }
};
