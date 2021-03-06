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
    ListNode* reverseList(ListNode* head) {
        /*Recursive*/
        if(!head || !head->next) return head;
        ListNode* rev = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev;
        
        /*Iteratively*/
        /*
        if(!head) return NULL;
        ListNode *cur,*pre;
        cur=head;
        pre=head;
        while(cur->next){
            head = cur->next;
            cur->next = cur->next->next;
            head->next = pre;
            pre=head;
        }
        return head;
        */
    }
};
