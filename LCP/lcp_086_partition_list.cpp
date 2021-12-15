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
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur=head;
        ListNode* LTH=new ListNode(-1);
        ListNode* GTH=new ListNode(-1);
        ListNode* curL=LTH;
        ListNode* curG=GTH;
        while(cur){
            if(cur->val < x){
                curL->next=cur;
                curL=curL->next;
            }
            else{
                curG->next=cur;
                curG=curG->next;
            }
            cur=cur->next;
        }
        curG->next=NULL;
        curL->next=GTH->next;
        return LTH->next;
        
    }
};
