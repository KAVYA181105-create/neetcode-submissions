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
    int maxDepth(TreeNode* root) {
        // how to find maximum dept in a binary tree ---> using recursion 
        if(root == NULL){
            return 0 ; 
        }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1+std::max(lh,rh);
    }
};
