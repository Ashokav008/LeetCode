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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL   )
            return NULL;
        
        if(!(head->next))
                return head;
        ListNode* prev=NULL,*newNode=nullptr ,*curr=head;
        
        while(curr){
        if(curr->next and curr->val==curr->next->val ){
            while(curr->next and curr->val==curr->next->val){
                curr=curr->next;
            }
        }
            else{
                if(!newNode)
                    newNode=curr;
                
                else
                    prev->next=curr;

                prev=curr;
            }
        
         curr=curr->next;   
        }
        
    if(prev)
     prev->next= NULL;
        return newNode;
    }
};