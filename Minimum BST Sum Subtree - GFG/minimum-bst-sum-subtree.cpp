//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int mini=INT_MAX;
    int currCnt=0;
   
    unordered_map<Node* , int>sumMap;
    unordered_map<Node* , bool>BSTMap;
    unordered_map<Node* , int>cntMap;
    bool isBST(Node* root, int mi,int ma){
        if(!root)
            return true;
        if(!root->left and !root->right)
            return BSTMap[root]=true;
            
        if(root->data<mi or root->data>ma)
            return BSTMap[root]= false;
            
        return BSTMap[root]= (isBST(root->left, mi, root->data) and isBST(root->right, root->data,ma));
    }
    bool isBSTUtil(Node* node, int minVal, int maxVal) {
    // Base case: an empty tree is a BST
    if (node == NULL)
        return true;

    // Check whether the node's data is within the given range
    if (node->data < minVal || node->data > maxVal)
        return false;

    // Recursively check the left and right subtrees
    return isBSTUtil(node->left, minVal, node->data - 1) && isBSTUtil(node->right, node->data + 1, maxVal);
}
    int getSum(Node* root){
       if(!root)
        return 0;
        
        if(!root->left and !root->right)
            return sumMap[root]=root->data;
        return sumMap[root]=  root->data +  getSum(root->left )+ getSum(root->right);
        
       
    }
    
    int getNodeCnt(Node* root){
        if(!root){
            return 0;
        }
        if(!root->left and !root->right){
            return cntMap[root]=1;
        }
        
        return cntMap[root]= 1+ getNodeCnt(root->left) + getNodeCnt(root->right);
    }
    
    void solve(Node* root, int target){
        if(!root)
            return;
        if(!root->left and !root->right){
            if(root->data==target)
                mini=1;
            return;
        }
        
        if(isBSTUtil(root,INT_MIN,INT_MAX)  ){
        //   if( BSTMap[root] ){
            // cout<<"BST FOUND AT "<<root->data<<endl;
            currCnt=0;
            if(sumMap[root]==target){
                // cout<<"tagget matched at this pos"<<endl;
                mini=min(mini,cntMap[root]);
            }
            currCnt=0;
        }
        solve(root->left,target);
        solve(root->right, target);
    }
    
    int minSubtreeSumBST(int target, Node *root) {
        getSum(root);
       
        // isBST(root,INT_MIN,INT_MAX);
        //  for(auto it: BSTMap){
        //     cout<<it.first->data<<" "<<it.second<<endl;
        // }
        getNodeCnt(root);
        solve(root,target);
        if(mini==INT_MAX)
        return -1;
        return mini;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends