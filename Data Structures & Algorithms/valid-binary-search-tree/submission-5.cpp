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
    bool isVALIDBST(TreeNode * root , int min , int max){
        if(root==nullptr){
            return true;
        }
        if(root->val >= max || root->val <= min){
            return false;
        }
        return isVALIDBST(root->left,min,root->val) && isVALIDBST(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        return isVALIDBST(root,INT_MIN,INT_MAX);
        
    }
};
