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
    vector<int> nodes;
    void inorderTraverse(TreeNode* root){
        if(!root) return;
        if(root->left) inorderTraverse(root->left);
        nodes.push_back(root->val);
        if(root->right) inorderTraverse(root->right);
    }
    
    TreeNode* constructBST(int low, int high){
        if(low>high) return NULL;
        int mid = (high+low)/2;
        TreeNode* n = new TreeNode(nodes[mid]);
        n->left = constructBST(low,mid-1);
        n->right = constructBST(mid+1,high);
        return n;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(!root->left && !root->right) return root;
        inorderTraverse(root);
        int n = nodes.size();
        return constructBST(0,n-1);
    }
};
