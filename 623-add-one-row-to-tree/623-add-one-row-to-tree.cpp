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
    
    void solve(TreeNode* &root, int val, int depth){
        
        if(!root)
                return;
   
        if(depth==1){
            
            TreeNode* node1=new TreeNode(val);
            TreeNode* node2=new TreeNode(val);
            
            node1->left=root->left;
            node2->right=root->right;
            root->left=node1;
            root->right=node2;
            return;
        }
        solve(root->left, val, depth-1);
             
        solve(root->right, val, depth-1);
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        
        if(depth==1){
            TreeNode* nroot=new TreeNode(val);
            nroot->left=root;
            return nroot;
        }
        
        solve(root, val, depth-1);
        return root;
        
    }
};