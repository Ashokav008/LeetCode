// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
       
       Node *p = head ;
       Node *q ;
       Node *r ;
       q=r=NULL ;
       
       Node *M ;
       Node *M_prev ;
       Node *N = head ;
       
       for(int i=0 ; i<m-1 ; i++)
       {
           r = q ;
           q = p ; 
           p = p->next ;
       }
       
       M_prev = q ;
       M = p ;
       
       for(int i=0 ; i<n-1 ; i++)
       {
           N = N->next ;
       }
       
       for(int i=0 ; i<n-m+1 ; i++)
       {
           r = q ;
           q = p ;
           p = p->next ;
           q->next = r ;
       }
       
       M->next = p ;
       if(M_prev != NULL)
       {
            M_prev->next = N ;
       }
      
       
       if(m==1)
       {
           head = q ;
       }
       
       return head ;
   }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends