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
    int s=0;
    void genGst(TreeNode* root){
        if(!root) return;
        genGst(root->right);
        s+=root->val;
        root->val = s;
        genGst(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        genGst(root);
        return root;
    }
    /*
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> nodeVal;
        getNodeVal(nodeVal,root);
        inorderTraverse(nodeVal,root);
        return root;
    }
    void getNodeVal(vector<int>& nodeVal, TreeNode* root){
        if(!root) return;
        getNodeVal(nodeVal,root->left);
        nodeVal.push_back(root->val);
        getNodeVal(nodeVal,root->right);
    }
    void inorderTraverse(vector<int>& nodeVal, TreeNode* root){
        if(!root) return;
        inorderTraverse(nodeVal,root->left);
        int tmp=root->val;
        for(int i=0;i<nodeVal.size();i++){
            if(root->val < nodeVal[i]){
                tmp+=nodeVal[i];
            }
        }
        root->val = tmp;
        inorderTraverse(nodeVal,root->right);
    }
    */
};
