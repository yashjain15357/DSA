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
    int maxSumHelper(TreeNode* root, int& ans) {
        if (root == NULL) return 0;
        
        // Agar left ya right ka sum negative hai, toh 0 le lo (yani unhe include mat karo)
        int left = max(0, maxSumHelper(root->left, ans));
        int right = max(0, maxSumHelper(root->right, ans));
        
        // Current node as a peak/split (Left -> Node -> Right)
        int current_path_sum = root->val + left + right;
        
        // Global answer ko update karo
        ans = max(ans, current_path_sum);
        
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxSumHelper(root, ans);
        return ans;
    }
};