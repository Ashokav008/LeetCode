// { Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


 // } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    Node* reverse(Node* head){
        Node* tmp=head;
        Node* curr=head,*prev=NULL,*next=NULL;
        
        while(curr->next!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            next=next->next;
        }
        
        curr->next=prev;
        
        // head=tmp;
        return curr;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
       Node* ans=new Node(-1);;
       Node* ans1=ans;
       ans->next=NULL;
       int carry=0;
      while(first!=NULL and second!=NULL){
          int add=first->data+second->data+carry;
          if(add>9)
              carry=1;
          else
            carry=0;
            
        add=add%10; 
        
        Node* tmp=new Node(add);
       ans->next=tmp;
       
        ans=ans->next;
        first=first->next;
        second=second->next;
        
      }
      
      while(first!=NULL){
          Node* tmp=new Node((first->data+carry)%10);
          if(first->data+carry>9)
            carry=1;
            else
              carry=0;
          
          ans->next=tmp;
          ans=ans->next;
          
          first=first->next;
      }
       while(second!=NULL){
           
          Node* tmp=new Node((second->data+carry)%10);
          if(second->data+carry>9)
            carry=1;
            else
              carry=0;
          
          ans->next=tmp;
          ans=ans->next;
          second=second->next;
      }
      
      if(carry>0){
          Node* tmp=new Node(1);
          
          ans->next=tmp;
          ans=ans->next;
          
          
      }
      
        ans->next=NULL;
        Node * ff=ans1->next;
        ans1->next=NULL;
        
        // cout<<ff->data<<endl;
        Node* ss=reverse(ff);
        
        return ss;
        
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
  // } Driver Code Ends