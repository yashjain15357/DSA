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
bool ans;
bool equal(TreeNode* root , TreeNode* subRoot){
    if(root == NULL && subRoot == NULL){
        return true;
    }
    if((root == NULL && subRoot != NULL) || (root!=NULL && subRoot == NULL)){
        return false;
    }
    bool left = equal(root->left , subRoot->left);
    bool right = equal(root->right , subRoot->right);
    if(root->val == subRoot->val && left && right){
        return true;

    }
    else{
        return false;
    }
    

}
void inorder(TreeNode* root , TreeNode* subRoot){
        if(root == NULL){
            return;
        }
        inorder(root->left , subRoot);
        if(root->val == subRoot->val){
            if(equal(root , subRoot)){
                ans = true;
                return;
            }
        }
        
        inorder(root->right , subRoot);

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        inorder(root , subRoot);
        return ans;
        
        
    }
};