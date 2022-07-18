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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(!root)
                return ans;
        q.push(root);
        
        while(!q.empty())
        {
            int sz=q.size();
            vector<int>v;
            while(sz--){
                auto front=q.front();
                q.pop();
                
                if(front->left!=NULL){
                    q.push(front->left);
                    v.push_back(front->left->val);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                    v.push_back(front->right->val);
                }
                
            }
            if(!v.empty())
            ans.push_back(v);
            
        }
        reverse(ans.begin(),ans.end());
        ans.push_back({root->val});
        return ans;
    }
};