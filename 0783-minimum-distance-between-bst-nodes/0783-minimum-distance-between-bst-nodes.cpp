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
private:
    int min_diff = INT_MAX;
    int prev = -1; // Stores the value of the previously visited node

    void inorder(TreeNode* root) {
        if (!root) return;

        // 1. Traverse left subtree
        inorder(root->left);

        // 2. Process current node
        if (prev != -1) {
            min_diff = min(min_diff, root->val - prev);
        }
        prev = root->val;

        // 3. Traverse right subtree
        inorder(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return min_diff;
    }
};