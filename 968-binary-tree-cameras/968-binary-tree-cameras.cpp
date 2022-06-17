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
    int notNeeded=-1,camera=1,noCamera=0;
    
    int solve(TreeNode* root){
        if(!root)
            return notNeeded;
        
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        if(l==noCamera or r==noCamera)
        {
            ans++;
            return camera;
        }
      else if(l==camera or r==camera)
            return notNeeded;
        
        else
           return noCamera;
        
    }
    int minCameraCover(TreeNode* root) {
           if(!root)
                return 0;
         ans=0;
      
        
       int x= solve(root);
        if(x==0)
                ans++;
        return ans;
    }
};