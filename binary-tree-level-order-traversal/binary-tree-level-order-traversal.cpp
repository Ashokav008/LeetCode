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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>v;
          if(root==NULL)
                return v;
      
        v.push_back({root->val});
        queue<TreeNode*>q;
        q.push(root);
      
        
        while(!q.empty()){
            int sz=q.size();
            vector<int>v1;
            
            while(sz--){
                
                TreeNode* it=q.front();
                q.pop();
                cout<<it->val<<endl;
                if(it->left!=NULL){
                    v1.push_back(it->left->val);
                    q.push(it->left);
                }
                if(it->right!=NULL)
                {
                    v1.push_back(it->right->val);
                    q.push(it->right);
                }
            }
            if(!v1.empty())
               v.push_back(v1);
        }
        return v;
    }
};