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
    int getSize(ListNode* head){
        
        int sz=0;
        while(head!=NULL)
        {
            sz++;
            head=head->next;
        }
        return sz;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int sz1=getSize(headA);
        int sz2=getSize(headB);
        
        // cout<<sz1<<"  "<<sz2<<endl;
        if(sz2>=sz1){
            int diff=sz2-sz1;
            while(diff--)
                headB=headB->next;
        }
        else{
            int sz=sz1-sz2;
            while(sz--)
                headA=headA->next;
            
        }
        while(headA!=NULL and headB!=NULL){
                if(headA==headB){
                    return headA;
                }
                headA=headA->next;
                headB=headB->next;
            }
            return NULL;
    }
};