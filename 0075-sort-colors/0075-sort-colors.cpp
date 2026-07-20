class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int k = 0;
        for(int i = 0 ; i<3 ; i++){
            int size = mp[i];
            for(int j = 0 ; j<size ; j++){
                nums[k] = i;
                k++;
            }
        }
        
        
    }
};