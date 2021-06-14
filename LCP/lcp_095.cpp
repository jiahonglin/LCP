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
    vector<TreeNode*> generateTrees(int n) {
        return genBST(1,n);
    }
    vector<TreeNode*> genBST(int start, int end){
        vector<TreeNode*> res;
        if(start > end){
            res.push_back(NULL);
            return res;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = genBST(start,i-1);
            vector<TreeNode*> right = genBST(i+1,end);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
