class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <=0) return intervals;

        // 1. Sort intervals by starting time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        // Start with the first interval
        ans.push_back(intervals[0]);

        for(int i = 1 ; i<intervals.size() ; i++){
            if(intervals[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);

            }
            else{
                ans.push_back(intervals[i]);

            }
        }
        return ans;



        
        
    }
};