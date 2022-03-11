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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head)
                return  nullptr;
        
        if(head->next==NULL)
            return head;
      
        list<int>l;
        ListNode*  tmp=head,*tmp1=head;
        
        while(tmp){
            l.push_back(tmp->val);
            tmp=tmp->next;
           
        }
        int sz=l.size();
        if(k==sz)
                return tmp1;
        if(sz==0)
                return NULL;
        
         int k1=k%sz;
        // cout<<"value of k1 is "<<k1<<"  size id"<<sz<<endl;
        while(k1--){
            int ele=l.back();
           l.pop_back();
            l.push_front(ele);
            // cout<<ele<<" ";
        }
        for(auto it:l){
          tmp1->val=it;
            tmp1=tmp1->next;
            // cout<<it<<"  ";
        }
        return head;
    }
};