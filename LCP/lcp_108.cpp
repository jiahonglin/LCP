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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arrayToBST(nums, 0, nums.size()-1);
    }
    TreeNode* arrayToBST(vector<int>& n, int start, int end)
    {
        if(end < start) return NULL;
        else
        {
            int mid = start + (end-start)/2;
            TreeNode* root = new TreeNode(n[mid]);
            root->left = arrayToBST(n, start, mid-1);
            root->right = arrayToBST(n, mid+1, end);
            return root;
        }
    }
};
