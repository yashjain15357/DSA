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
    bool inorder_fun(TreeNode* left_root , TreeNode* right_root){
        if(left_root == NULL && right_root == NULL){
            return true;
        }
        
        if((left_root == NULL && right_root != NULL) || (left_root != NULL && right_root == NULL) ){
            return false;
        }
        if(left_root->val != right_root->val ) return false;

    bool left = inorder_fun(left_root->left , right_root->right);
    bool right = inorder_fun(left_root->right , right_root->left);

    if(left && right){
        return true;
    }
    else{
        return false;
    }

    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return false;
        }
        if(!root->left && !root->right) return true;
        bool ans  = inorder_fun(root->left , root->right);
        return ans;
        
    }
};