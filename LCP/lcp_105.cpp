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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return processTree(0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder);
    }
    TreeNode* processTree(int preLeft, int preRight, int inLeft, int inRight, vector<int>& pre, vector<int>& in){
        if(preRight < preLeft || inRight < inLeft)
            return NULL;
        TreeNode *root = new TreeNode(pre[preLeft]);
        int rootPos = 0;
        for(int i=0; i<=inRight-inLeft;i++){
            if(pre[preLeft] == in[inLeft+i]){
                rootPos = inLeft+i;
                break;
            }
        }
        
        root->left = processTree(preLeft+1, preLeft+rootPos-inLeft, inLeft, inLeft+rootPos-1, pre, in);
        root->right = processTree(preLeft+rootPos-inLeft+1, preRight, rootPos+1, inRight, pre, in);
        return root;
    }
};
