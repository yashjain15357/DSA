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
bool fun_same(TreeNode* p , TreeNode*q){
    if(q==NULL && p==NULL){
        return true;
    }
    if((q==NULL && p!=NULL) || (q!=NULL && p==NULL)){
        return false;
    }
    if(q->val != p->val){
        return false;
    }
    bool left = fun_same(p->left , q->left);
    bool right = fun_same(p->right , q->right);
    if(left && right){
        return true;
    }
    else{
        return false;
    }
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = fun_same(p , q);
        return ans;
        
    }
};