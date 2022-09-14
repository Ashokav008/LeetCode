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
    int ans=0;
    unordered_map<int,int>mp;
    void solve(TreeNode* root){
        
        
       mp[root->val]+=1;
      
        if(root->left==NULL and root->right==NULL){
            // cout<<"Insdei leaf  "<<root->val<<endl;
            int cnt=0;
            for(auto it:mp){
                // cout<<it.first<<" "<<it.second<<endl;
                if(it.second%2==1)
                        cnt++;
                if(cnt>1)
                        break;
            }
            if(cnt<=1)
               ans+=1;
           
        }
    if(root->left)
      solve(root->left);
    if(root->right)
      solve(root->right);
        
     mp[root->val]-=1;
        if(mp[root->val]==0)
                mp.erase(mp[root->val]);
       
    
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
      ans=0;
         solve(root);
     
        return ans;
    }
};