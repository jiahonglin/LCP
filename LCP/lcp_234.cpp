/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *cur=head;
        return recurvisit(head,cur);
        /*
        vector<int> num;
        ListNode *cur = head;
        int size=0;
        while(cur){
            num.push_back(cur->val);
            cur=cur->next;
            size++;
        }
        
        for(int i=0;i<size/2;i++){
            if(num[i] != num[size-1-i])
                return false;
        }
        
        return true;
        */
    }
    bool recurvisit(ListNode *node, ListNode* &cur){
        if(!node) return true;
        bool res = recurvisit(node->next, cur) && (node->val == cur->val);
        cur = cur->next;
        return res;
    }
};
