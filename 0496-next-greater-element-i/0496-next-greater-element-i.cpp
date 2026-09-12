class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        unordered_map<int , int >mp;

        for(int num : nums2){
            while(!st.empty() && st.top()<num){
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        for(int i = 0 ; i<nums1.size() ; i++){
            if(mp[nums1[i]]){
                nums1[i] = mp[nums1[i]];
            }
            else{
                nums1[i] = -1;
            }
        }
        return nums1;

        
        
    }
};