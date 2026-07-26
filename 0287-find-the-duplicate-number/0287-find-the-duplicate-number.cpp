class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int , bool>mp;
        for(int i : nums){
            if(mp[i]){
                return i;
            }
            mp[i]=true;
            
        }
        return 0;
        
    }
};