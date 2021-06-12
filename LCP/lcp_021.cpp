/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        /*Recursive*/

        ListNode *result;
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val){
            result = l1;
            result->next = mergeTwoLists(l1->next,l2);
        }
        else{
            result = l2;
            result->next = mergeTwoLists(l1,l2->next);
        }
        return result;
        
        
        /*Iterative*/
        /*
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(l1 && l2){
            if(l1->val > l2->val){
                cur->next = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                l1 = l1->next;
            }
            cur = cur->next;
        }
        cur->next=l1?l1:l2;
        return dummy->next;
        */
    }
};
