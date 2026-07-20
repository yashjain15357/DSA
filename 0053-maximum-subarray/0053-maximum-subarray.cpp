class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int currsum = 0;
        int ans = INT_MIN;
        
        for(int i = 0 ; i<nums.size() ; i++){
            currsum += nums[i];
            ans = max(currsum , ans);
            if(currsum<0){
                currsum = 0;

            }
            


        }
        
        return ans;
    }
};