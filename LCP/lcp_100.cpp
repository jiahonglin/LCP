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
    /*Iterative*/
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty()){
            TreeNode *c1, *c2;
            c1 = q1.front(); q1.pop();
            c2 = q2.front(); q2.pop();
            if(!check(c1,c2)) return false;
            if(c1){
                if(!check(c1->left,c2->left)) return false;
                else{
                    q1.push(c1->left);
                    q2.push(c2->left);
                }
            }
            if(c2){
                if(!check(c1->right,c2->right)) return false;
                else{
                    q1.push(c1->right);
                    q2.push(c2->right);
                }
            }
        }
        return true;
    }
    bool check(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return true;
    }
    /*Recursive*/
    /*
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
    }
    */
};
