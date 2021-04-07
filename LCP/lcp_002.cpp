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
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        int carry=0;
        while(l1 || l2){
            int val1 = l1?l1->val:0;
            int val2 = l2?l2->val:0;
            int sum = val1 + val2 + carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            cur=cur->next;
        }
        if(carry) cur->next=new ListNode(1);
        return dummy->next;

        /*
        ListNode *seq1 = l1;
        ListNode *seq2 = l2;
        ListNode *longlist, *shortlist;
        ListNode *curL, *curS;
        ListNode *pre;
        int size1=0;
        int size2=0;
        bool adv=false;
        while(seq1){seq1=seq1->next; size1++;}
        while(seq2){seq2=seq2->next; size2++;}
        if(size1>size2){
            longlist = l1;
            shortlist = l2;
        }
        else{
            longlist = l2;
            shortlist = l1;
        }
        curL = longlist;
        curS = shortlist;
        while(curL && curS){
            adv=false;
            int sum = curL->val + curS->val;
            if(sum/10 > 0){
                curL->val = sum-10;
                pre=curL;
                curL = curL->next;
                curS = curS->next;
                if(curL){
                    curL->val+=1;
                    adv=true;
                }
                else{
                    adv=true;
                    break;
                }
            }
            else{
                curL->val = sum;
                curL = curL->next;
                curS = curS->next;
            }
        }
        
        while(curL){
            adv=false;
            if(curL->val/10>0){
                curL->val = curL->val-10;
                pre=curL;
                curL = curL->next;
                if(curL){
                    curL->val+=1;
                    adv=true;
                }
                else{
                    adv=true;
                    break;
                }
            }
            else{
                curL = curL->next;
            }     
        }
        if(adv){
            ListNode *tmp = new ListNode(1,NULL);
            pre->next = tmp;
        }
        return longlist;
        */
    }
};

