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
    
   bool isBST(TreeNode* root, long long int maxi,long long int mini){
       
       if(!root)
            return true;
       if(root->val<=mini or root->val>=maxi)
            return false;
       
       return isBST(root->left, root->val,mini) and isBST(root->right, maxi,root->val);
   }
    
    bool isValidBST(TreeNode* root) {
        
        if(!root)
                return true;
        if(!root->left and !root->right)
        return true;
        
        return isBST(root, 1e18,-1e18);
        
    }
};