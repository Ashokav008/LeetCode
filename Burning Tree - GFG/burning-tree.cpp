// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int ans=1;
  unordered_map<Node* ,  Node*> mp ;
 
 Node *T=NULL ;
 
 
 unordered_map<Node*, bool > visited ;
 
 void PreOrder(Node *root,int target)
 {
     if(!root)
        return ;
     
     if(root->data==target)
     T = root ;
     if(root->left)
     {
         mp[root->left] =root ;
     }
     if(root->right)
     {
         mp[root->right] = root ;
     }
     
     PreOrder(root->left,target) ;
     PreOrder(root->right,target) ;
 }
    int minTime(Node* root, int target) 
    {
        
        if(!root)
            return 0 ;
            
        mp[root] = NULL ;
        int t= 0;
        Node* r=root;
        
         PreOrder(root, target);
     
         
         queue<Node* > q ;
         q.push(T);
         
         while(!q.empty())
         {
             int sz=q.size(); 
             
             while(sz--)
             {
                 Node *temp = q.front() ;
                 q.pop();
                
                 
                
                  if(temp->left and !visited[temp->left])
                  {
                    q.push(temp->left) ;visited[temp->left] =1 ;
                      
                  }
                 
                 if(temp->right and !visited[temp->right])
                 {
                    q.push(temp->right)  ; visited[temp->right]=1 ;
                     
                 }
                    
                if(mp[temp]and !visited[mp[temp]])
                 {
                   
                    q.push(mp[temp]) ;visited[mp[temp]]=1;
                    
                 }
             }
           
             t++ ;
         }
        return t-1;
    }
        

};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends