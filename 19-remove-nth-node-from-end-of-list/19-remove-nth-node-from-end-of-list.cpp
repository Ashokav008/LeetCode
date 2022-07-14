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
    int findLength(ListNode* head){
        
        int ans=0;
        ListNode* tmp=head;
        while(head!=NULL){
            head=head->next;
            ans++;
        }
        
        return ans;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=findLength(head);
        
        if(head->next==NULL){
            return NULL;
        }
      cout<<len<<endl;
        ListNode* tmp=head;
        
        if(n==len){
            return head->next;
        }
        int rN=len-n-1;
        while(rN--){
           tmp=tmp->next;
            
        }
        cout<<tmp->val<<endl;
        ListNode* curr=tmp;
        ListNode* next=tmp->next->next;
       
        tmp->next=next;
        
        return head;
        
        
    }
};