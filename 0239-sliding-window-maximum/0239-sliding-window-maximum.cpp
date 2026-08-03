class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // time limit exceeded
        // vector<int>ans;
        // if(nums.size()<k){
        //     return ans;
        // }
        // int mx = nums[0];
        // int mx_index=0;
        
        // int p1 =0;
        // int p2=k-1;
        // while(p2<nums.size()){
        //     if(p1>=mx_index){
        //         mx=nums[p1];
        //         for(int i = p1 ; i<=p2 ; i++){
        //             if(nums[i]>mx){
        //                 mx = nums[i];
        //                 mx_index = i;
        //             }
        //         }
        //         ans.push_back(mx);
        //     }
        //     else if(nums[p2]>=mx){
        //         mx=nums[p2];
        //         mx_index = p2;
        //         ans.push_back(mx);
        //     }
        //     else{
        //         ans.push_back(mx);
        //     }
        //     p1++;
        //     p2++;

        // }
        // return ans; 
        deque<int> dq; // Stores indices of array elements
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove indices that are out of the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Remove indices of all elements smaller than the current element nums[i]
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Add current element's index
            dq.push_back(i);

            // 4. The front of deque is always the index of the maximum element
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;   
    }
};