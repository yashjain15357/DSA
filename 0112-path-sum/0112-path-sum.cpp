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
    bool path(TreeNode* root, int targetSum ,int sum){
        if(root == NULL){
            return false;
        }
        sum+=root->val;
        if(sum==targetSum && root->left ==NULL && root->right==NULL){
            return true;
        }
        bool left = path(root->left , targetSum, sum);
        bool right = path(root->right , targetSum , sum);

        return left || right ?true:false; 

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return NULL;
        }
        int sum = 0;
        return path(root , targetSum, sum);

        


        
    }
};