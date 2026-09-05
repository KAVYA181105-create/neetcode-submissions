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

// DIAMETER OF BINARY TREE MEANS --->> THE LENGTH OF LONGEST PATH BETWEEN ANY TWO NODES

class Solution {
public:
    int binaryTreeDepth(TreeNode* root){
        if(root==NULL){
            return 0 ;
        }
        int left_height =  binaryTreeDepth(root->left);
        int right_height = binaryTreeDepth(root->right);
        return (1 + max(left_height , right_height));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int max_diameter = INT_MIN ;
        int leftSideDepth = binaryTreeDepth(root->left);
        int rightSideDepth = binaryTreeDepth(root->right);
        max_diameter = rightSideDepth + leftSideDepth;
        int left_diameter = diameterOfBinaryTree(root->left);
        int right_diameter = diameterOfBinaryTree(root->right);
        return (max({max_diameter,left_diameter,right_diameter}));
    }
};
