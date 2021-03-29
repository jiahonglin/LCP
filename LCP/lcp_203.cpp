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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        while(pre->next){
            if(pre->next->val == val){
                ListNode *t = pre->next;
                pre->next = t->next;
                t->next=NULL;
                delete t;
            }
            else{
                pre = pre->next;
            }
        }
        return dummy->next;
        /*
        if(!head) return NULL;
        ListNode *cur = head;
        while(cur->next){
            if(cur->next->val == val){
                cur->next = cur->next->next;
            }
            else{
                cur=cur->next;
            }
        }
        return (head->val==val)?head->next:head;
        */
    }
};
