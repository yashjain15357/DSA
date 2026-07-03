class Solution {
public:
    int maxDiameter = 0;

    // This function returns the height of the tree
    int calculateHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // Recursively find the height of left and right subtrees
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);

        // The diameter at the current node is leftHeight + rightHeight
        // Update the maximum diameter found so far
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current subtree to the parent node
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0; // Reset for each test case
        calculateHeight(root);
        return maxDiameter;
    }
};