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
    void order(Node* root , vector<int>&ans){
        if(root==NULL){
            return;
        }
        int child_NO = root->children.size();
        
        ans.push_back(root->val);
        for(int i = 0 ; i<child_NO ; i++){

            order(root->children[i] , ans);
        }
        
    }
    vector<int> preorder(Node* root) {
        vector<int>ans;
        order(root , ans);
        return ans;
        
    }
};