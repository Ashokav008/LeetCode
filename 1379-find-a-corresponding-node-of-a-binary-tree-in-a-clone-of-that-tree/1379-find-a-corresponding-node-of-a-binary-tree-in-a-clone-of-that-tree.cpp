/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* res;
 void inOrder(TreeNode* org, TreeNode* clone, TreeNode* target) {
        if (org) {
            inOrder(org->left, clone->left, target);
            if (org == target) {
				 res = clone;
				 return;
			}
            inOrder(org->right, clone->right, target);
        }
    }
	
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        inOrder(original, cloned, target);
        return res;
    }

    
};