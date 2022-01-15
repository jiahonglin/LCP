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
    /*Morris Traversal : O(1) space solution*/
    void recoverTree(TreeNode* root) {
        TreeNode *cur=root;
        TreeNode *first=NULL;
        TreeNode *second=NULL;
        TreeNode *pre=NULL;
        while(cur){
            if(cur->left){
                TreeNode *p=cur->left;
                while(p->right && p->right!=cur) p=p->right;
                if(!p->right){
                    p->right=cur;
                    cur=cur->left;
                    continue;
                }
                else{
                    p->right=NULL;
                }
            }
            if(pre && pre->val > cur->val){
                if(!first) first=pre;
                second=cur;
            } 
            pre=cur;
            cur=cur->right;
        }
        swap(first->val,second->val);
    }
    
    /*Recursive method*/
    /*
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> tn;
        vector<int> nums;
        inorderTraverse(root, tn, nums);
        sort(nums.begin(),nums.end());
        for(int i=0;i<tn.size();i++){
            tn[i]->val = nums[i];
        }
    }
    void inorderTraverse(TreeNode* root, vector<TreeNode*>& tn, vector<int>& nums){
        if(!root) return;
        inorderTraverse(root->left, tn, nums);
        tn.push_back(root);
        nums.push_back(root->val);
        inorderTraverse(root->right,tn,nums);
    }
    */
};
