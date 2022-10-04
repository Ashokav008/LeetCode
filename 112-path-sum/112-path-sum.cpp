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
    bool solve( TreeNode* root,int  tSum){
        
        if(!root)
                return false;
        if(root->left==NULL and root->right==NULL and tSum==root->val)
                return true;
        tSum=tSum-root->val;
         return solve(root->left,tSum) or solve(root->right,tSum);
        
    }
    
    bool hasPathSum(TreeNode* root, int tSum) {
     
        return solve(root, tSum);
        
    }
};