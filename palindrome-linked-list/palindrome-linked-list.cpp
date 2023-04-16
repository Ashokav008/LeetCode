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
   
    ListNode* reverse(ListNode* head){
       ListNode* curr=head,*prev=NULL,*next=NULL;
        while(curr->next!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            next=next->next;
        }
    
      curr->next=prev;
        ListNode* tmp=curr;
        cout<<"Reversed : "<<endl;
        while(tmp){
            cout<<tmp->val<<" ";
            tmp=tmp->next;
        }

        cout<<endl;
        return curr;
    }
  bool isPalindrome(ListNode* head) {
	ListNode *slow = head, *fast = head, *prev = NULL, *tmp;
	while(fast && fast -> next) // finding mid point
		fast = fast -> next -> next,
		tmp = slow -> next, slow -> next = prev, prev = slow, slow = tmp;        
	slow = (fast ? slow -> next : slow); // for odd length case as mentioned above
	while(slow) // check if linked lists starting at prev and slow are equal
		if(slow -> val != prev -> val) return false;
		else slow = slow -> next, prev = prev -> next;
	return true;
}
};