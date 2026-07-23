class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if(intervals.size() <=0) return intervals;

        // // 1. Sort intervals by starting time
        // sort(intervals.begin(), intervals.end());
        // vector<vector<int>> ans;
        // // Start with the first interval
        // ans.push_back(intervals[0]);


        // for(int i = 1 ; i<intervals.size() ; i++){
        //     if(intervals[i][0] <= ans.back()[1]){
        //         ans.back()[1] = max(ans.back()[1], intervals[i][1]);

        //     }
        //     else{
        //         ans.push_back(intervals[i]);

        //     }
        // }
        // return ans;


        if(intervals.size() <=0) return intervals;

        // 1. Sort intervals by starting time
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        // Start with the first interval
        // ans.push_back(intervals[0]);
        if(intervals.size() <=1) return intervals;
        
        
        for(int i = 1 ; i<intervals.size() ; i++){
            if(intervals[i][0] <= intervals[i-1][1]){
                intervals[i-1][1] = max(intervals[i-1][1], intervals[i][1]);
                intervals.erase(intervals.begin()+i);
                i--;

            }
            else{
                ans.push_back(intervals[i]);

            }
        }
        return intervals;



        
        
    }
};