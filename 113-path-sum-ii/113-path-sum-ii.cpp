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
    vector<vector<int>>ans;
    
    void solve(TreeNode* root, int targetSum, int mySum , vector<int>&path){
        
        if(!root)
                return;
        path.push_back(root->val);
        mySum+=root->val;
       cout<<root->val<<"   "<<mySum<<endl;
        
        if(mySum==targetSum and root->left==NULL and root->right==NULL){
            ans.push_back(path);
            path.pop_back();
            return; 
        }
        
        if(root->left ){
                solve(root->left, targetSum, mySum , path);
        }
        if(root->right ){
                solve(root->right, targetSum, mySum , path);
        }
        path.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int>path;
        int mySum=0;
        solve(root, targetSum , mySum , path);
        return ans;
    }
};