/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // void(Node* root , vector<vector<int>> &ans){
    //     if(root == NULL){
    //         return ans;
    //     }

    // }
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        // ans.push_back([root->val]);
        while(!q.empty()){
           
            int levelsize = q.size();
            
            vector<int> child;
            for(int i = 0 ;i<levelsize ; i++){
                Node* temp = q.front();
                q.pop();
                child.push_back(temp->val);
                for (Node* child : temp->children) {
                    if (child != nullptr) {
                        q.push(child);
                    }
}
            }
            ans.push_back(child);


        }
        return ans;


    }
};