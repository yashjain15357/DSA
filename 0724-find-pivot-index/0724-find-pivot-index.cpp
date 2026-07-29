class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i =0 ; i<nums.size();i++){
            sum+=nums[i];
        }
        
        int ls=0;
        int rs=0;
        for(int i = 0 ; i<=(nums.size()-1); i++){
            
            int rs = sum-nums[i]-ls;
            if(ls==rs){
                return i;
            }
            
            
                ls+=nums[i];    
            
        }
        // for(int i = nums.size()-1 ; i>=0 ; i--){
        //     ls = sum-nums[i]-rs;
        //     if(ls==rs){
        //         return i;
        //     }
        //     rs += nums[i];

        // }
             
        return -1;
        
        
    }
};