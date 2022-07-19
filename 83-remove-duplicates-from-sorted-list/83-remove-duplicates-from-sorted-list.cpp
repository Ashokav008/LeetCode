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
        if(!head or head->next==NULL)
                return head;
        
        
         ListNode* ans=head;
        int data=head->val;
        while(head!=NULL){
            ListNode* tmp=head;
            data=tmp->val;
            while(tmp!=NULL and tmp->val==data){
                cout<<tmp->val<<endl;
                tmp=tmp->next;
            }
      
            head->next=tmp;
            head=head->next;
        }
        return ans;
        
    }
};