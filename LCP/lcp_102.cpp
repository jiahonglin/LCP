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
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<TreeNode*, int> NodeMap;
        TreeNode* cur;
        int level = 0;
        queue<TreeNode*> NodeQueue,NodeQueue2;
        vector<vector<int>> sol;
        if(root)
        {
            NodeQueue.push(root);
            NodeMap.insert(pair<TreeNode*, int>(root, level));
        }
        else
        {
            return sol;
        }
        while(NodeQueue.empty() == false)
        {
            cur = NodeQueue.front();
            NodeQueue.pop();
            NodeQueue2.push(cur);
            int tmplevel = NodeMap[cur] + 1;
            level = (level>tmplevel?level:tmplevel);
            if(cur->left)
            {
                NodeMap.insert(pair<TreeNode*, int>(cur->left, tmplevel));
                NodeQueue.push(cur->left);
            }
            if(cur->right)
            {
                NodeMap.insert(pair<TreeNode*, int>(cur->right, tmplevel));
                NodeQueue.push(cur->right);
            }
        }
 
	int nowLevel = 0;
        vector<int>tmpsol;
        while(NodeQueue2.empty() == false)
        {
            TreeNode* tmp  = NodeQueue2.front();
            NodeQueue2.pop();
            if(nowLevel >= NodeMap[tmp])
            {
                tmpsol.push_back(tmp->val);
            }
            else
            {
                sol.push_back(tmpsol);
                tmpsol.clear();
                tmpsol.push_back(tmp->val);
                nowLevel = NodeMap[tmp];
            }
        }
        if(tmpsol.empty() == false)
            sol.push_back(tmpsol);
        return sol;
    }
};
