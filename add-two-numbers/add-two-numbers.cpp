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
    ListNode* addTwoNumbers(ListNode* t1, ListNode* t2) {
        vector<int>v1;
        vector<int>v2;
        if(t1==NULL)
                return t2;
    if(t2==NULL)
            return t1;
        
        while(t1!=NULL){
            v1.push_back(t1->val);
            t1=t1->next;
        }
        while(t2!=NULL){
            v2.push_back(t2->val);
            t2=t2->next;
        }
        vector<int>v3;
        int a=v1.size(),b=v2.size();
        for(auto it:v1){
            cout<<it<<" ";
        }
        cout<<endl;
         for(auto it:v2){
            cout<<it<<" ";
        }
        // cout<<a<<b<<endl;
        
        int i=0,j=0;
        while(i<a or j<b){
            int add=0;
            if(i<a )
                add+=v1[i];
            if(j<b)
                add+=v2[j];
            
            v3.push_back(add);
            i++,j++;
        }
        cout<<endl;
         for(auto it:v3){
            cout<<it<<" ";
        }
        
        ListNode* ans=new ListNode(v3[0]),*final1;
        int carry=0;
        if(v3[0]>9){
                ans->val=v3[0]%10;
                carry=1;
        }
        final1=ans;
        // reverse(v3.begin(),v3.end());
           for(int i=1;i<v3.size();i++){
                
               int add=v3[i]+carry;
               if(add>9)
               {
                   add=add%10;
                   carry=1;
               }
               else
                    carry=0;
               
               ListNode* tmp=new ListNode(add);
               final1->next=tmp;
               final1=final1->next;
               
               
           }
        if(carry==1){
            ListNode* tmp= new ListNode(1);
            final1->next=tmp;
            final1=final1->next;
        }
        final1->next=NULL;
        return ans;
                
        // return t1;
    }
};