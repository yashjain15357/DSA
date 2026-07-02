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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            int levelsize = st.size();
            vector<int> currentLevel;
                for(int i = 0; i<levelsize ; i++){

                TreeNode* temp = st.front();
                st.pop();
                currentLevel.push_back(temp->val);

                if(temp->left){
                    st.push(temp->left);
                }
                if(temp->right){
                    st.push(temp->right);
                }
            }
            ans.push_back(currentLevel);

        }
        return ans;
        
    }
};