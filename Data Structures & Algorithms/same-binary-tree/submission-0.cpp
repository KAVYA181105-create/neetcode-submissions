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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* temp = p ;
        TreeNode* temp2 = q ; 
        while(temp != NULL || temp2 != NULL){
            if(temp==NULL || temp2==NULL){
                return false;
            }
            if(temp->val == temp2->val){
                temp = temp->left;
                temp2 = temp2->left;
            }
            else{
                return false;
            }
        }
        TreeNode* temp3 = p ;
        TreeNode* temp4 = q ; 
        while(temp3!=NULL || temp4 !=NULL){
            if(temp3 == NULL || temp4==NULL){
                return false;
            }
            if(temp3->val== temp4->val){
                temp3= temp3->right;
                temp4 = temp4->right;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
