/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
                return NULL;
        
        queue<Node*>q;
        q.push(root);
        root->next=NULL;
        
        while(!q.empty()){
           int sz=q.size();
             
            queue<Node*>q2;
            while(sz--){
                Node* front=q.front();
                q.pop();
                if(front->left){
                    q2.push(front->left);
                    q2.push(front->right);
                    q.push(front->left);
                    q.push(front->right);
                }
               
            }
             while(!q2.empty()){
                    Node* front=q2.front();
                    q2.pop();
                 if(q2.size()==0){
                     front->next=NULL;
                        }
                 else
                    front->next=q2.front();
                }
            
        }
        return root;
    }
};