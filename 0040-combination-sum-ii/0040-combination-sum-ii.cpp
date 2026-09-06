class Solution {
public:
    
    void fun(vector<vector<int>> &ans , vector<int>&curr , int indx , vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        

        for(int i = indx ; i<candidates.size() ; i++){
            if(target<candidates[i]){
                break;
            }
            if (i > indx && candidates[i] == candidates[i - 1]) continue;


                curr.push_back(candidates[i]);

                fun(ans,curr , i+1 , candidates , target-candidates[i] );

                curr.pop_back();
            
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int>curr;
        int indx = 0;
        fun(ans , curr , indx ,candidates, target);
        return ans;

        
    }
};