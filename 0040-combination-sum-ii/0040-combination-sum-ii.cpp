class Solution {
public:
    void findCombinations(int start, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result) {
        // Base Case: Found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // Optimization: If the number exceeds remaining target, stop (array is sorted)
            if (candidates[i] > target) break;

            // Skip duplicate elements at the same depth level
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // 1. Choose
            current.push_back(candidates[i]);
            
            // 2. Explore (move to next index `i + 1`)
            findCombinations(i + 1, target - candidates[i], candidates, current, result);
            
            // 3. Un-choose (Backtrack)
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, target, candidates, current, result);
        return result;
    }
};