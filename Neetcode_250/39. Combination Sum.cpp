class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& path, int index) {
        if (target == 0) {
            result.push_back(path); //found a valid combination
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue; //ignore if no.is too big
            
            path.push_back(candidates[i]); //choose the number
            backtrack(candidates, target - candidates[i], result, path, i);
            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result; //store all combinations
        vector<int> path;
        backtrack(candidates, target, result, path, 0); //backtrack from 0
        return result;
    }
};







