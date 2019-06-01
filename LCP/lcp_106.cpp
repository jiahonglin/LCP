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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return processTree(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder);
    }

    TreeNode* processTree(int inLeft, int inRight, int postLeft, int postRight, vector<int>& in, vector<int>& post){
        int rootPos=0;
        if(inLeft > inRight || postLeft > postRight){
            return NULL;
        }
        TreeNode* root = new TreeNode(post[postRight]);
        for(int i = 0; i <= inRight-inLeft ; i++){
            if(in[inLeft+i] == post[postRight]){
                rootPos = i; 
                break;
            }
        }
        root->right = processTree(inLeft+rootPos+1, inRight, postLeft+rootPos, postRight-1, in, post);
        root->left = processTree(inLeft, inLeft+rootPos-1, postLeft, postLeft+rootPos-1, in, post);
      return root;  
    }

};
