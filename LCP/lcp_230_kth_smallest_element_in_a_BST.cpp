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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        preOrder(root,nums);
        return nums[k-1];
    }
    void preOrder(TreeNode* root, vector<int>& nums){
        if(!root) return;
        preOrder(root->left,nums);
        nums.push_back(root->val);
        preOrder(root->right,nums);
    }
};
