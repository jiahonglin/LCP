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
    ListNode *detectCycle(ListNode *head) {
        /*
        vector<ListNode*> rec;
        if(head == NULL) return NULL;
        rec.push_back(head);
        ListNode *cur = head;
        while(cur->next != NULL){
            cur=cur->next;
            for(int i=0;i<rec.size();i++){
                if(rec[i] == cur){
                    return cur;
                }
            }
            rec.push_back(cur);
        }
        return NULL;
        */
        ListNode *fast, *slow, *meetNode=NULL;
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                meetNode = slow;    
                break;
            } 
        }
        if(meetNode==NULL) return NULL;
        slow = head;
        while(slow!=meetNode){
            slow = slow->next;
            meetNode = meetNode->next;
        }
        return slow;
    }
};
