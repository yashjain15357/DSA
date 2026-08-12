class Solution {
public:
void candidate(vector<vector<int>> &ans , vector<int> &temp , vector<int>& candidates, int target , int i ){
    if(target == 0 ){
        ans.push_back(temp);
        return;
    }
    if(target < 0 ){
        
        return;
    }
    if(i == candidates.size())
            return;
    candidate(ans , temp ,candidates , target ,i+1);
    temp.push_back(candidates[i]);
    candidate(ans , temp ,candidates , target-candidates[i] ,i);
    temp.pop_back();

    
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        int i = 0;
        candidate(ans , temp ,candidates , target ,0);
        
        return ans;
    }
};