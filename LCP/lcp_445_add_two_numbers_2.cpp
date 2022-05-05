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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode *curr1=l1;
        ListNode *curr2=l2;
        ListNode *head=NULL;
        ListNode *last=NULL;
        int carry=0;
        while(curr1 != NULL || curr2 != NULL){
            int sum=0;
            if(curr1 != NULL) {
                sum+=curr1->val;
                curr1=curr1->next;
            }
            if(curr2 != NULL){
                sum+=curr2->val;
                curr2 = curr2->next;
            }
            sum+=carry;
            if(sum >= 10){
                sum%=10;
                carry = 1;
            }
            else{
                carry=0;
            }
            insert(&head,&last,sum);
        }
        if(carry==1) insert(&head,&last,carry);

        return reverseList(head);        
    }

    ListNode* reverseList(ListNode* head){
        if(!head) return NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* precede = head->next;
        while(curr){
            curr->next = prev;
            prev = curr;
            curr = precede;
            if(!precede) return prev;
            precede = precede->next;
        }
        return prev;
    }

    void insert(ListNode **head, ListNode **last, int x){
        if((*head)==NULL && (*last)==NULL){
            (*head) = (*last) = new ListNode(x);
        }
        else{
            ListNode* tmp = new ListNode(x);
            (*last)->next = tmp;
            (*last) = tmp;
        }
    }
};
