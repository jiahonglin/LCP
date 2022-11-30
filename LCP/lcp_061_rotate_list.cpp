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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *cur = head;
        ListNode *fast = head, *slow = head;
        int size = 0;
        while(cur){
            cur = cur->next;
            size++;
        }
        k%=size;
        for(int i=0;i<k;i++){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        fast = slow->next;
        slow->next = NULL;
        return fast;
    }
};
