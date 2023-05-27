//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
     
        stack<int>stk;
        Node* tmp=head;
        while(tmp!=NULL){
            stk.push(tmp->data);
            tmp=tmp->next;
        }
        
        tmp=head;
        int n=stk.size();
        int i=1;
        while(i<=n/2){
            tmp->data=stk.top()-tmp->data;
            stk.pop();
            tmp=tmp->next;
            i++;
            
        }
        if(n%2)
            {
                i++;
                stk.pop();
                tmp=tmp->next;
            }
      while(i<=n){
        //   cout<<i<<"   "<<stk.top()<<endl;
          tmp->data=stk.top();
          stk.pop();
          tmp=tmp->next;
            i++;
      }
       return head;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends