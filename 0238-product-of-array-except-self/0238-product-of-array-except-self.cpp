class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int p1=0;
        int p2=nums.size()-1;
        vector<int> arr1;
        vector<int> arr2;
        int product1=1 , product2 =1;
        
        while(p1<nums.size()){
            arr1.push_back(product1);
            arr2.push_back(product2);
            product1 = product1*nums[p1];
            product2 = product2*nums[p2];
            p1++;
            p2--;

        }
        for(int i = 0 ; i<nums.size() ; i++){
            nums[i] = arr1[i]*arr2[nums.size()-1-i];
        }
        return nums;

    }
};