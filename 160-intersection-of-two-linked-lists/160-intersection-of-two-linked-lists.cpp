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
    int countNode(ListNode* a){
        if(a==NULL)
                return 0;
        int cnt=0;
        while(a!=NULL){
            a=a->next;
            cnt++;
        }
        
        return cnt;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=countNode(headA);
        int l2=countNode(headB);
        ListNode* ans=NULL;
        if(l1<l2){
            int len=l2-l1;
            while(len>0){
                headB=headB->next;
                len--;
            }
        }
        else if(l1>l2){
              int len=l1-l2;
            while(len>0){
                headA=headA->next;
                len--;
            }
        }
        
        while(headA!=headB){
            // if(headA==headB){
            //     ans=headA;
            //     return ans;
            // }
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
        // return ans;
    }
};