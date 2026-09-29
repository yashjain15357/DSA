class Solution {
public:
int max_dia = 0;
int fun_tree_height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int left = fun_tree_height(root->left);
    int right = fun_tree_height(root->right);

    max_dia = max(max_dia , left+right);
    int ans = max(left , right)+1;
    return ans;



}
    

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        fun_tree_height(root);
        
        return max_dia;
       
    }
};