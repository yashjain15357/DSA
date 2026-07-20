class Solution {
public:
    void sortColors(vector<int>& nums) {
        // unordered_map<int , int> mp;
        // for(int i : nums){
        //     mp[i]++;
        // }
        // int k = 0;
        // for(int i = 0 ; i<3 ; i++){
        //     int size = mp[i];
        //     for(int j = 0 ; j<size ; j++){
        //         nums[k] = i;
        //         k++;
        //     }
        // }
        
        // three pointer method
        int s = 0 ;
        int e = nums.size()-1;
        int m = 0;

        while(m<=e){
            if(nums[m]>1){
                swap(nums[m] , nums[e]);
                e--;
            }
            else if(nums[m] == 1){
                m++;
            }
            else{
                swap(nums[m] , nums[s]);
                s++;
                m++;
            }
        }
        
    }
};