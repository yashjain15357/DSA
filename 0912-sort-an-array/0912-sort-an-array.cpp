class Solution {
public:

void merge(vector<int> &nums , vector<int>& temp , int s , int mid , int e){
    if(nums[mid] <= nums[mid+1]) return ;

    int i = s , j = mid+1 , k  = s;

    while(i<=mid && j<=e){
        if(nums[i]<=nums[j]){
            temp[k++] = nums[i++];
        }
        else{
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= e) temp[k++] = nums[j++];
    for (int p = s; p <= e; p++) {
        nums[p] = temp[p];
    }
}
void mergesort(vector<int>&nums ,vector<int>&temp, int s , int e){
    if(s>=e){
        return ;
    }
    int mid = s + (e - s) / 2;

    mergesort(nums ,temp , s , mid);
    mergesort(nums ,temp, mid+1 , e);
    merge(nums , temp , s , mid , e);

}
    vector<int> sortArray(vector<int>& nums) {
        vector<int > temp(nums.size());
        mergesort(nums , temp , 0 , nums.size()-1);
        return nums;
        
    }
};