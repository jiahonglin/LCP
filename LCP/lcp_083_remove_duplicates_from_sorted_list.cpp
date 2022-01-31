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
        ListNode* cur = head;
        int nowVal = 0;
        while(cur && cur->next){
            nowVal = cur->val;
            if(cur->next->val > nowVal){
                cur=cur->next;
            }
            else{
                ListNode* p = cur->next;
                while(p->next && p->next->val == nowVal) p=p->next;
                cur->next=p->next;
                cur=cur->next;
            }
        }
        return head;
    }
};
