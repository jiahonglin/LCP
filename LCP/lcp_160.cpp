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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        if(headA == NULL || headB == NULL) return NULL;
        vector<ListNode*>recA;
        ListNode *cur=headA;
        while(cur != NULL){
            recA.push_back(cur);
            cur = cur->next;
        }
        cur=headB;
        while(cur!=NULL){
            for(int i=0;i<recA.size();i++){
                if(recA[i]==cur){
                    return cur;
                }
            }
            cur = cur->next;
        }
        return NULL;
        */
        double lenA=0,lenB=0;
        ListNode *curA, *curB;
        curA = headA;
        curB = headB;
        while(headA != NULL) {lenA++; headA=headA->next;}
        while(headB != NULL) {lenB++; headB=headB->next;}
        if(lenA > lenB){
            int diff = lenA-lenB;
            while(diff > 0) {curA=curA->next; diff--;}
        }
        else{
            int diff = lenB-lenA;
            while(diff > 0) {curB=curB->next; diff--;}
        }
        while(curA!=NULL && curB!=NULL){
            if(curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
