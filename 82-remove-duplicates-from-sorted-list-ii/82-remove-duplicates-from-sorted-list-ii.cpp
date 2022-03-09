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

 // if the no. of nodes are 0 or 1, just return
 if( !head || !(head->next))
     return head;
 
 // prev & curr are used for connecting prev with current unique node and newhead is the
 //head of the new modified linked list
 ListNode* prev = NULL, *curr= head, *newhead = nullptr;
 
 /// while curr node exists
 while( curr){

     if(curr->next && curr->val == curr->next->val){
         
         // move to the last same_value node
         while( curr->next && curr->val == curr->next->val){
             curr= curr->next;
         }
     }
     
     
     else{
        
         if( !newhead)
             newhead= curr;
     
         else
             prev->next = curr;
            
         //change the prev_node to the curr_node (it will serve as prev for the next unique node
         prev = curr;
     }
     
    
     curr= curr->next;

 }
 if(prev)
     prev->next= NULL;
 
 return newhead;
}

};