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
//     int isBST(Node* root){
//       if(!root)
//                 return true;
//         int rootData=root->val;
//         int left=isValidBST(root->left);
//         int right=isValidBST(root->right);
        
//         if(rootData>left and rootData<right)
//                 return true;
//         else
//                 return false;
//     }  
     vector<int>ans;
    void inOrder(TreeNode* root){
        
        if(!root)
                return;
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
        
    }
    
    bool isValidBST(TreeNode* root) {
        ans.clear();
        inOrder(root);
        
        for(int i=1;i<ans.size();i++){
            if(ans[i]<=ans[i-1])
                    return false;
        }
        return true;
    }
};