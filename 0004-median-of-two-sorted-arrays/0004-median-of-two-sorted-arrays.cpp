class Solution {
public:
   
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // big O(m+n) approach
        // vector<int>arr;
        // int p1=0 ;
        // int p2=0;
        // while(p1<nums1.size() && p2<nums2.size()){
        //     if(nums1[p1] <= nums2[p2]){
        //         arr.push_back(nums1[p1]);
        //         p1++;
        //     }
        //     else{
        //         arr.push_back(nums2[p2]);
        //         p2++;
        //     }
        // }
        // while(p1<nums1.size()){
        //     arr.push_back(nums1[p1]);
        //      p1++;
        // }
        // while(p2<nums2.size()){
        //     arr.push_back(nums2[p2]);
        //     p2++;
        // }
        // double ans;
        // int s = arr.size();
        
        // if(s%2 == 0){
        //     ans = (arr[s/2] + arr[(s/2)-1])/2.0;
        //     return ans;
        // }
        // else{
        //     ans = arr[s/2];
        //     return ans;

        // }

        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        
        int targetIndex = total / 2;
        int p1 = 0, p2 = 0;
        
        int prev = 0, curr = 0;

        // Traverse only up to the median position
        for (int i = 0; i <= targetIndex; i++) {
            prev = curr;
            
            // Safely fetch current values or assign INT_MAX if out of bounds
            int val1 = (p1 < m) ? nums1[p1] : INT_MAX;
            int val2 = (p2 < n) ? nums2[p2] : INT_MAX;
            
            if (val1 < val2) {
                curr = val1;
                p1++;
            } else {
                curr = val2;
                p2++;
            }
        }

        // Return exact float average for even length, or middle element for odd length
        if (total % 2 == 0) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
        
                
    }
};