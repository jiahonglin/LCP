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
    /*Method 1*/
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* prev=NULL;
        ListNode* cur=head;
        for(int i=0;i<left-1;i++){
            prev=cur;
            cur=cur->next;
        }
        ListNode* revEnd=cur;
        ListNode* last=prev;
        ListNode* next=cur->next;
        for(int i=0;i<right-left+1;i++){
            cur->next=prev;
            prev=cur;
            cur=next;
            if(next)
                next=next->next;
        }
        if(last)
            last->next=prev;
        else
            head=prev;
        revEnd->next=cur;
        return head;
    }

    /*Method 2*/
    /*
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<int> node;
        ListNode* cur=head;
        while(cur){
            node.push_back(cur->val);
            cur=cur->next;
        }
        reverse(node.begin()+left-1,node.begin()+right);
        cur=head;
        for(int i=0;i<node.size();i++){
            cur->val=node[i];
            cur=cur->next;
        }
        return head;
    }
    */
};
