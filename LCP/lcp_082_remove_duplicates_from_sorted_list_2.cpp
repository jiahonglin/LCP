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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* root=new ListNode(0);
        ListNode* cur=head;
        ListNode* prev=root;
        int cnt=0;
        while(cur){
            cnt=0;
            while(cur->next && cur->val == cur->next->val){
                cur=cur->next;
                cnt++;
            }
            if(cnt == 0){
                prev->next=cur;
                prev=cur;
            }
            cur=cur->next;
        }
        prev->next=NULL;
        return root->next;
    }
};
