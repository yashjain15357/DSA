class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + ((high - low)/2) ;
            
            if(mid+1<nums.size()  && mid-1 >=0){
                if(nums[mid-1]!=nums[mid] && nums[mid+1] != nums[mid]){
                    return nums[mid];
                }
                else if(mid%2==0 ){
                    if(nums[mid-1] == nums[mid]){
                        high = mid;

                    }
                    else{
                        low = mid;
                    }
                }
                else{
                    if (nums[mid-1] == nums[mid]){
                        low = mid+1;
                    }
                    else{
                        high = mid-1;
                    }
                }


            }
            else{
                return nums[mid];
            }
        }
        return -1;
    }
};