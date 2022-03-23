// { Driver Code Starts
#include <iostream>

using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



Node *swapkthnode(Node* head, int num, int K);

void addressstore(Node **arr, Node* head)
{
    Node* temp = head;
    int i = 0;
    while(temp){
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node ** before, Node **after, int num, int K)
{
    if(K > num)
        return 1;
    return (before[K-1] == after[num - K]) && (before[num-K] == after[K-1]);
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int num, K , firstdata;
        cin>>num>>K;
        int temp;
        cin>>firstdata;
        Node* head = new Node(firstdata);
        Node* tail = head;
        for(int i = 0; i<num - 1; i++){
            cin>>temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }
        
        Node *before[num];
        addressstore(before, head);
        
        head = swapkthnode(head, num, K);
        
        Node *after[num];
        addressstore(after, head);
        
        if(check(before, after, num, K))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends


//User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

//Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node* head, int num, int k)
{
   if(k>num)
       return head;
   if(k>num/2)
       k = num-k+1;
   
   if(num==1)
       return head;
       
   if(k==1){
       Node* ptr1=head;
       Node* ptr2=head;
       Node* ptr3=NULL;
       while(ptr2 -> next){
           ptr2=ptr2 -> next;
           if(ptr3==NULL)
               ptr3=head;
           else
               ptr3=ptr3 -> next;
       }
       
       ptr2 -> next = ptr1 -> next;
       ptr3 -> next=ptr1;
       ptr1 -> next=NULL;
       head=ptr2;
       return head;
   }
   
   Node* ptr1=head;
   Node* ptr2=head;
   int count=1;
   
   while(ptr1!=NULL && count<k){
       ptr1=ptr1 -> next;
       ++count;
   }
   Node* ptr3=ptr1;
   while(ptr3 -> next){
       ptr2=ptr2 -> next;
       ptr3=ptr3 -> next;
   }
   
   if(ptr2==ptr1)
       return head;
   
   ptr3=head;
   while(ptr3 -> next!=ptr2)
       ptr3=ptr3 -> next;
   
   Node* ptr4=head;
   while(ptr4 -> next!=ptr1)
       ptr4=ptr4 -> next;
   
   ptr4 -> next = ptr2;
   ptr3 -> next=ptr1;
   Node* ptr5=ptr2 -> next;
   ptr2 -> next=ptr1 -> next;
   ptr1 -> next=ptr5;
   return head;
}