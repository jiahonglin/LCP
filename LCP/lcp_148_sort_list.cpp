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
    /*Merge sort*/
    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* newHead = new ListNode(0);
        ListNode *tmp = newHead;
        while(list1 && list2){
            if(list1->val <= list2->val){
                tmp->next = list1;
                list1=list1->next;
            }
            else{
                tmp->next = list2;
                list2=list2->next;
            }
            tmp=tmp->next;
        }
        tmp->next=list1!=NULL?list1:list2;
        return newHead->next;
    }

    ListNode* getMid(ListNode* head){
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next && fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *mid=getMid(head);
        ListNode *list1 = head;
        ListNode *list2 = mid->next;
        mid->next=NULL;
        
        list1 = sortList(list1);
        list2 = sortList(list2);
        return merge(list1,list2);
    }
    
    /*Insertion sort:TLE*/
    /*
    ListNode* sortList(ListNode* head) {
        ListNode *dummy=new ListNode(-1);
        ListNode *cur=dummy;
        while(head){
            ListNode *t=head->next;
            cur=dummy;
            while(cur->next && cur->next->val < head->val){
                cur=cur->next;
            }
            head->next=cur->next;
            cur->next=head;
            head=t;
        }
        return dummy->next;
    }
    */
    /*
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode *cur=head;
        while(cur) {nums.push_back(cur->val); cur=cur->next;}
        sort(nums.begin(),nums.end());
        cur=head;
        int idx=0;
        while(cur){
            cur->val=nums[idx];
            cur=cur->next;
            idx++;
        }
        return head;
    }
    */
};
