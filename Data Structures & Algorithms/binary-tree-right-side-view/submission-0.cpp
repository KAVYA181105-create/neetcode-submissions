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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode* > q;
        vector<int> v1;
        if(root ==NULL){
            return v1;
        }
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> v2;
            while(n--){
                TreeNode * front = q.front();
                q.pop();
                 if(front->left !=NULL){
                   q.push(front->left);   
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
                v2.push_back(front->val);
            }
            int n1 = v2.size();
            v1.push_back(v2[n1-1]);
        }
        return v1;
    }
};
