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

    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int ans=0;
        sumPath(root,0,ans);
        return ans;
    }
    void sumPath(TreeNode* root, int sum, int& ans){
        if(!root) return;
        if(!root->left && !root->right){
            ans = ans + sum*10 + root->val;
            return;
        }
        if(root->left){
            sum = sum*10 + root->val;
            sumPath(root->left, sum, ans);
            sum = sum/10;
        }
        if(root->right){
            sum = sum*10 + root->val;
            sumPath(root->right, sum, ans);
            sum = sum/10;
        }
    }

/*    
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> allPath;
        vector<int> path;
        listPath(root,path,allPath);
        int sol=0;
        for(int i=0;i<allPath.size();i++){
            int numDigit=allPath[i].size()-1;
            long int factor=1;
            while(numDigit >= 0){
                sol+=allPath[i][numDigit]*factor;
                factor*=10;
                numDigit--;
            }
        }
        return sol;
    }
    void listPath(TreeNode* root, vector<int> path, vector<vector<int>>& allPath){
        if(root) path.push_back(root->val);
        if(!root->left && !root->right){
            allPath.push_back(path);
            path.pop_back();
        }
        if(root->left) listPath(root->left, path, allPath);
        if(root->right) listPath(root->right, path, allPath);
    }
*/
};
