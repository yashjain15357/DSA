/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;
        Node* temp = head;

        // Step 1: Saare original nodes ke liye naye nodes banao
        while (temp) {
            mp[temp] = new Node(temp->val);
            temp = temp->next; // Loop aage badhane ke liye
        }

        temp = head;

        // Step 2: Hash Map ki madad se naye pointers connect karo
        while (temp) {
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }

        return mp[head]; // Cloned list ka head return karo
    }
};