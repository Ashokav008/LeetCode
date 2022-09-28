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
    int countTotalNodes(ListNode* head){
        int cnt=0;
        while(head!=NULL){
                head=head->next;
            cnt++;
        }
        return cnt;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total=countTotalNodes(head);
        
        if(total==1 and n==1)
                return NULL;
        
        int pos=total-n;
        ListNode * curr=head;
        if(pos==0){
            
            return head->next;
            
        }
        
        while(pos--){
           
            if(pos==0){
                
                if(curr->next==NULL)
                        curr= NULL;
                else{
                    
                    curr->next=curr->next->next;
                    
                }
                
            }
             curr=curr->next;
                
            }
        
    return head;
        
    }
};