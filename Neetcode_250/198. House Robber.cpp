class Solution {
private:
    int solve(int i, vector<int>& nums, vector<int>& memo) {
        if (i >= nums.size()) return 0;
        if (memo[i] != -1) return memo[i];
        int robCurrent = nums[i] + solve(i + 2, nums, memo);
        int skipCurrent = solve(i + 1, nums, memo);
        return memo[i] = max(robCurrent, skipCurrent);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return solve(0, nums, memo);
    }
};