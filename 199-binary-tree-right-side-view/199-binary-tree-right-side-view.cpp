/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        queue<TreeNode*>q;
        if(!root)
                return v;
        
        q.push(root);
        while(!q.empty()){
            v.push_back(q.front()->val);
            int sz=q.size();
            
            while(sz--){
                TreeNode* front=q.front();
                q.pop();
                
                if(front->right!=NULL)
                    q.push(front->right); 
                
                if(front->left!=NULL)
                    q.push(front->left);     
                
            }
        
        }
        return v;
    }
};