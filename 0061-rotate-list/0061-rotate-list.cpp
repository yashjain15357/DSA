/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        stack<ListNode*>st;
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
        k = k%st.size();
        if (k == 0) return head;
        for(int i = 0 ; i<k ; i++){
            ListNode* element = st.top();
            element->next = head;
            head = element;
            st.pop();
        }
        st.top()->next = NULL;
        return head;
        
    }
};