class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr;
        int p1=0 ;
        int p2=0;
        while(p1<nums1.size() && p2<nums2.size()){
            if(nums1[p1] <= nums2[p2]){
                arr.push_back(nums1[p1]);
                p1++;
            }
            else{
                arr.push_back(nums2[p2]);
                p2++;
            }
        }
        while(p1<nums1.size()){
            arr.push_back(nums1[p1]);
             p1++;
        }
        while(p2<nums2.size()){
            arr.push_back(nums2[p2]);
            p2++;
        }
        double ans;
        int s = arr.size();
        
        if(s%2 == 0){
            ans = (arr[s/2] + arr[(s/2)-1])/2.0;
            return ans;
        }
        else{
            ans = arr[s/2];
            return ans;

        }

        
    }
};