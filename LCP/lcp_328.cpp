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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *pre,*cur;
        pre = head;
        cur = head->next;
        while(cur&&cur->next){
            ListNode *t = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = t;
            pre=pre->next;
            cur=cur->next;
        }
        return head;
    }
};
