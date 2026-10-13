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
    int ans;
    void nod (int &k ,TreeNode* root ){
        if(root== NULL){
            return;
        }
        
        nod(k , root->left );
        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        nod(k , root->right );
        

    }
    int kthSmallest(TreeNode* root, int k) {
        nod(k , root);
        return ans;
    }
};