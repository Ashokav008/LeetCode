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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>v;
        if(!root)
                return v;
        vector<int>v1;
        v1.push_back(root->val);
        
        bool flg=true;
        v.push_back(v1);
        while(!q.empty()){
           
            v1.clear();
            int n=q.size();
            while(n--){
                 TreeNode* front=q.front();
                 q.pop();
                if(front->left!=NULL){
                            q.push(front->left);
                            v1.push_back(front->left->val);
                }
                if(front->right!=NULL)
                {
                        q.push(front->right);
                         v1.push_back(front->right->val);
                }
            }
            
            if(flg)
            {
                reverse(v1.begin(),v1.end());
                
            }
            if(!v1.empty())
                 v.push_back(v1);
            flg=!flg;
        }
        return v;
    }
};